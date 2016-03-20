//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <cenvir.h>
#include <cmessage.h>
#include <cobjectfactory.h>
#include <cpacketqueue.h>
#include <cpar.h>
#include <cqueue.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <distrib.h>
#include <IPoIBFrameIB_m.h>
#include <IPoIBLayer.h>
#include <IPv4ARPTotf_m.h>
#include <IPv4PacketIBS_m.h>
#include <QPsendCompletion_m.h>
#include <regmacros.h>
#include <simtime.h>
#include <simutil.h>
#include <cstring>
#include <iostream>
#include <utility>

Define_Module(IPoIBLayer);

void IPoIBLayer::initialize() {
    // TODO - Generated method body
    LocalNodeLID = par("thisHcaPortLID");
    LocalNodePKey = par("thisHCAPortPkey");
    broadcastLID = par("broadcastLID");
    broadcastPkey = par("pKey");
    sourceIP = par("SourceIP").stringValue();
    QueuePairBuffSize = par("QPBufSize");
    ipQUeue = new cPacketQueue(NULL, NULL);

    // New Introduced codes For correcting QoS values start
    for (int i = 0; i < 16; i++) {
        ipQUeueForQoS[i] = new cPacketQueue(NULL, NULL);
    }

    // New Introduced codes For correcting QoS values end

    //   ipQUeue->setTakeOwnership(true);
    scheduleInterval = par("scheduleInterval");
    timer = new cMessage("IPoIBLayerTimer");
    scheduleAt(simTime() + this->scheduleInterval, timer);
}

void IPoIBLayer::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    if (msg->isSelfMessage()) {
        // module triggered locally

        // Modified Self message events for QoS Start

        EV<<"ipQUeueForQoS[15]->length() = "<<ipQUeueForQoS[15]->length();

        for (int i = 15; i >= 0; i--) {
            for (int j = 0; j < ipQUeueForQoS[i]->length(); j++) {
                if (!ipQUeueForQoS[i]->isEmpty()) {
                    tempIPPacket =
                            dynamic_cast<IPv4PacketIBS *>(ipQUeueForQoS[i]->front());
                    IPoIBARPCacheIterator = IPoIBARPCache.find(
                            tempIPPacket->getDestinationIP());
                    if (IPoIBARPCacheIterator == IPoIBARPCache.end()) {
                        ARPRequestedCacheIterator = ARPRequestedCache.find(
                                tempIPPacket->getDestinationIP());
                        // no entry found in ARP Cache for the destination IP. Initiate IPoIB ARP Request
                        if (ARPRequestedCacheIterator
                                == ARPRequestedCache.end()) {
                            // no earlier ARP Request has been sent. So sent a new ARP Request
                            tempIPARPRequest = new IPv4ARPTotf(
                                    "IPv4ARPTotf Request");
                            tempIPARPRequest->setSourceIP(
                                    tempIPPacket->getSourceIP());
                            tempIPARPRequest->setDestinationIP(
                                    tempIPPacket->getDestinationIP());
                            tempIPARPRequest->addByteLength(28); // size of ARP IP packet
                            // encapsulate it inside an IPoIBARP Request
                            tempIPoIBARPRequest = new IPoIBFrameIB(
                                    "IPoIBARP Request");
                            tempIPoIBARPRequest->setSLid(this->LocalNodeLID);
                            tempIPoIBARPRequest->setDLid(this->broadcastLID);
                            tempIPoIBARPRequest->setPkey(this->broadcastPkey);
                            tempIPoIBARPRequest->setSl(
                                    tempIPPacket->getAppid());
                            tempIPoIBARPRequest->setVl(
                                    tempIPPacket->getAppid());
                            tempIPoIBARPRequest->setFrameType(0); // frame type = 0 to denote this IPoIB Frame is an ARP packet
                            tempIPoIBARPRequest->setKind(0);
                            tempIPoIBARPRequest->addByteLength(30); // LRH(8B)+BTH(12B)+ICRC(4B)+IPoIBHeader(4B)+VCRC(2B) = 30Bytes
                            tempIPoIBARPRequest->encapsulate(tempIPARPRequest);

                            send(tempIPoIBARPRequest->dup(), "toBelowSendQ");
                            ARPRequestedCache[tempIPPacket->getDestinationIP()] =
                                    true;
                        } else {
                            // ARP Request has already been sent
                        }

                    } else {
                        // Destination IP found in ARP Cache. Initiate IPoIB Packet Transfer
                        // Delete me Start
                        EV << "Creating an IPoIB Data Frame" << endl;
                        // Delete me End
                        if (QueuePairBuffSize) {
                            // if QueuePairBuffSize != 0, means send queue is not full. So it is ok to inject to it
                            // create a new IPoIB Data Frame and send to below queue pair
                            tempIPoIBFrame = new IPoIBFrameIB(
                                    "IPoIBData Frame");
                            tempIPoIBFrame->setSLid(this->LocalNodeLID);
                            //      tempIBHWAddress = IPoIBARPCache[tempIPPacket->getDestinationIP()];
                            tempIPoIBFrame->setDLid(
                                    IPoIBARPCacheIterator->second->getLID());
                            tempIPoIBFrame->setPkey(this->LocalNodePKey);
                            tempIPPacket =
                                    dynamic_cast<IPv4PacketIBS *>(ipQUeueForQoS[i]->pop());
                            tempIPoIBFrame->setSl(tempIPPacket->getAppid());
                            tempIPoIBFrame->setVl(tempIPPacket->getAppid()); // we are assuming each SL is mapped to same VL
                            tempIPoIBFrame->setFrameType(1); // frame type 0 means IPoIB ARP, 1 means IPoIB Data Frame
                            tempIPoIBFrame->addByteLength(30); // LRH(8B)+BTH(12B)+ICRC(4B)+IPoIBHeader(4B)+VCRC(2B) = 30Bytes
                            tempIPoIBFrame->encapsulate(tempIPPacket);
                            tempIPoIBFrame->setKind(1);
                            tempIPoIBFrame->setTimestamp(simTime());

                            QueuePairBuffSize--; // decrease the QP buffer size
                            send(tempIPoIBFrame->dup(), "toBelowSendQ");
                        }
                    }
                }
            }
        }
        // Modified Self message events for QoS End

//        if (!ipQUeue->isEmpty()) {
//            tempIPPacket = dynamic_cast<IPv4PacketIBS *>(ipQUeue->front());
//            IPoIBARPCacheIterator = IPoIBARPCache.find(
//                    tempIPPacket->getDestinationIP());
//            if (IPoIBARPCacheIterator == IPoIBARPCache.end()) {
//                ARPRequestedCacheIterator = ARPRequestedCache.find(
//                        tempIPPacket->getDestinationIP());
//                // no entry found in ARP Cache for the destination IP. Initiate IPoIB ARP Request
//                if (ARPRequestedCacheIterator == ARPRequestedCache.end()) {
//                    // no earlier ARP Request has been sent. So sent a new ARP Request
//                    tempIPARPRequest = new IPv4ARPTotf("IPv4ARPTotf Request");
//                    tempIPARPRequest->setSourceIP(tempIPPacket->getSourceIP());
//                    tempIPARPRequest->setDestinationIP(
//                            tempIPPacket->getDestinationIP());
//                    tempIPARPRequest->addByteLength(28);
//                    // encapsulate it inside an IPoIBARP Request
//                    tempIPoIBARPRequest = new IPoIBFrameIB("IPoIBARP Request");
//                    tempIPoIBARPRequest->setSLid(this->LocalNodeLID);
//                    tempIPoIBARPRequest->setDLid(this->broadcastLID);
//                    tempIPoIBARPRequest->setPkey(this->broadcastPkey);
//                    tempIPoIBARPRequest->setSl(tempIPPacket->getAppid());
//                    tempIPoIBARPRequest->setVl(tempIPPacket->getAppid());
//                    tempIPoIBARPRequest->setFrameType(0); // frame type = 0 to denote this IPoIB Frame is an ARP packet
//                    tempIPoIBARPRequest->setKind(0);
//                    tempIPoIBARPRequest->addByteLength(30); // LRH(8B)+BTH(12B)+ICRC(4B)+IPoIBHeader(4B)+VCRC(2B) = 30Bytes
//                    tempIPoIBARPRequest->encapsulate(tempIPARPRequest);
//
//
//                    send(tempIPoIBARPRequest->dup(), "toBelowSendQ");
//                    ARPRequestedCache[tempIPPacket->getDestinationIP()] = true;
//                } else {
//                    // ARP Request has already been sent
//                }
//
//            } else {
//                // Destination IP found in ARP Cache. Initiate IPoIB Packet Transfer
//                // Delete me Start
//                EV << "Creating an IPoIB Data Frame" << endl;
//                // Delete me End
//                if (QueuePairBuffSize) {
//                    // if QueuePairBuffSize != 0, means send queue is not full. So it is ok to inject to it
//                    // create a new IPoIB Data Frame and send to below queue pair
//                    tempIPoIBFrame = new IPoIBFrameIB("IPoIBData Frame");
//                    tempIPoIBFrame->setSLid(this->LocalNodeLID);
//                    //      tempIBHWAddress = IPoIBARPCache[tempIPPacket->getDestinationIP()];
//                    tempIPoIBFrame->setDLid(
//                            IPoIBARPCacheIterator->second->getLID());
//                    tempIPoIBFrame->setPkey(this->LocalNodePKey);
//                    tempIPPacket = dynamic_cast<IPv4PacketIBS *>(
//                            ipQUeue->pop());
//                    tempIPoIBFrame->setSl(tempIPPacket->getAppid());
//                    tempIPoIBFrame->setVl(tempIPPacket->getAppid()); // we are assuming each SL is mapped to same VL
//                    tempIPoIBFrame->setFrameType(1); // frame type 0 means IPoIB ARP, 1 means IPoIB Data Frame
//                    tempIPoIBFrame->addByteLength(30); // LRH(8B)+BTH(12B)+ICRC(4B)+IPoIBHeader(4B)+VCRC(2B) = 30Bytes
//                    tempIPoIBFrame->encapsulate(tempIPPacket);
//                    tempIPoIBFrame->setKind(1);
//                    tempIPoIBFrame->setTimestamp(simTime());
//
//                    QueuePairBuffSize--; // decrease the QP buffer size
//                    send(tempIPoIBFrame->dup(), "toBelowSendQ");
//                }
//            }
//        }
        delete msg;
        timer = new cMessage("IPoIBLayerTimer");
        scheduleAt(simTime() + this->scheduleInterval, timer);
    } else if (msg->arrivedOn("fromIPAppGen1")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen2")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen3")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen4")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen5")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen6")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen7")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen8")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen9")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen10")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen11")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen12")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen13")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen14")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen15")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromIPAppGen16")) {
        // arrived from IP Application
        tempIPPacket = dynamic_cast<IPv4PacketIBS *>(msg);
        //ipQUeue->insert(tempIPPacket->dup());
        ipQUeueForQoS[tempIPPacket->getAppid()]->insert(tempIPPacket->dup());
    } else if (msg->arrivedOn("fromBelowRecvQ")) {
        // Recieved an IPoIBFrame
        tempIPoIBFrame = dynamic_cast<IPoIBFrameIB *>(msg);
        if (tempIPoIBFrame->getFrameType() == 0) {
            // Deleteme start
            EV << "Received an IPoIBARP Frame" << endl;
            EV << "tempIPoIBFrame->getDLid() = " << tempIPoIBFrame->getDLid()
                      << " and LocalNodeLID = " << LocalNodeLID << endl;
            // End delete
            // IPoIBARP Reply received. Update the ARP cache
            if (tempIPoIBFrame->getDLid() == this->LocalNodeLID) {
                // IPoIB ARP Reply received
                tempIPARP =
                        dynamic_cast<IPv4ARPTotf *>(tempIPoIBFrame->decapsulate());
                IPoIBARPCache[tempIPARP->getSourceIP()] = new IBHardWAddress(
                        tempIPoIBFrame->getSLid(), tempIPoIBFrame->getPkey());
                // Remove the ARP Requested entry from the ARPRequestedCache
                ARPRequestedCache.erase(
                        ARPRequestedCache.find(tempIPARP->getSourceIP()));
            } else if (tempIPoIBFrame->getDLid() == this->broadcastLID) {
                // Deleteme start
                EV << "Received a broadcast IPoIBARP reqest" << endl;
                // End delete
                // IPoIB ARP request received;
                tempIPARP =
                        dynamic_cast<IPv4ARPTotf *>(tempIPoIBFrame->decapsulate());
                // check for if it is for this node
                if (strcmp(tempIPARP->getDestinationIP(),
                        this->sourceIP.c_str()) == 0) {
                    // Deleteme start
                    EV << "sending IPoIBARP Reply" << endl;
                    // End delete
                    // send ARP Reply
                    tempIPARPReply = new IPv4ARPTotf("IPv4ARPTotfReply");
                    tempIPARPReply->setSourceIP(tempIPARP->getDestinationIP());
                    tempIPARPReply->setDestinationIP(tempIPARP->getSourceIP());
                    tempIPARPReply->addByteLength(28);

                    // encapsulate it inside an IPoIBReply
                    tempIPoIBARPReply = new IPoIBFrameIB("IPoIBARP Reply");
                    tempIPoIBARPReply->setSLid(this->LocalNodeLID);
                    tempIPoIBARPReply->setDLid(tempIPoIBFrame->getSLid());
                    tempIPoIBARPReply->setPkey(tempIPoIBFrame->getPkey());
                    tempIPoIBARPReply->setSl(tempIPoIBFrame->getSl());
                    tempIPoIBARPReply->setVl(tempIPoIBFrame->getVl());
                    tempIPoIBARPReply->addByteLength(30); //// LRH(8B)+BTH(12B)+ICRC(4B)+IPoIBHeader(4B)+VCRC(2B) = 30Bytes
                    tempIPoIBARPReply->setKind(0);
                    tempIPoIBARPReply->encapsulate(tempIPARPReply);

                    send(tempIPoIBARPReply->dup(), "toBelowSendQ");

                } else {
                    // ignore or drop the ARP request since it is requesting another node
                    delete (msg);
                }

            }
        } else if (tempIPoIBFrame->getFrameType() == 1) {
            // IPoIB Data frame received

            tempRecvIPPacket =
                    dynamic_cast<IPv4PacketIBS *>(tempIPoIBFrame->decapsulate());

            send(tempRecvIPPacket->dup(), "toIPoIBSink");
            // delete the received frame
            delete tempIPoIBFrame;
        }
    } else if (msg->arrivedOn("fromBelowCompletionQ")) {
        // Received an completion event
        tempQPCompletionStat = dynamic_cast<QPsendCompletion *>(msg);
        if (tempQPCompletionStat->getSendSuccessStat()) {
            // Send Queue has successfully sent an IPoIB Frame. So increase the QP buffer size
            QueuePairBuffSize++;
            EV << "Successfully sent an IPoIB Frame (ARP or Data Frame)"
                      << endl;
            delete (msg); // exhaust the received stat message to prevent deadlock with future stat messages
        } else {
            //failed QP send operation. Currently this feature is not used. Kept for future support.
        }
    }
}

int IPoIBLayer::generateSL() {
    return uniform(0, 16); // Returns a random variate with uniform distribution in the range [a,b).
}

void IPoIBLayer::finish() {

}
