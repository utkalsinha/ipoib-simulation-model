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

#include <cmessage.h>
#include <cobjectfactory.h>
#include <cpar.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <distrib.h>
#include <IPTrafficGenerator.h>
#include <IPv4PacketIBS_m.h>
#include <regmacros.h>
#include <simtime.h>
#include <simutil.h>
#include <cmath>

Define_Module(IPTrafficGenerator);

void IPTrafficGenerator::initialize() {
    // TODO - Generated method body
    numberOfBytesToSend = par("numberOfBytesToCreateAndSend"); // or message size or file size in bytes
    MTUSize = par("mtuSize");
    appid = par("AppGenID");
    sourceIP = par("SourceIP").stringValue();
    destinationIP = par("DestinationIP").stringValue();
    netMask = par("netmask").stringValue();

    tcpHeaderSizeInBytes = 20; // TCP Header size has minimum = 20B and maximum = 60B
    udpHeaderSizeInBytes = 8; // UDP has an 8 bytes header field;
    IPv4HeaderSizeInBytes = 20; // IP Layer appends a minimum of 20 Bytes header

    effectiveIPFragmentSize = MTUSize - IPv4HeaderSizeInBytes
            - udpHeaderSizeInBytes;

    numOfFullMTUPackets = numberOfBytesToSend / effectiveIPFragmentSize;
    remainningByteLength = numberOfBytesToSend % effectiveIPFragmentSize;
    if(remainningByteLength){
        remainingBytesSent = false;
    }else{
        remainingBytesSent = true;
    }

    // delete me start
    numberOfPings = 20;
    // delete me end

    pktSeqNum = 1;
    willGeneratePackets = par("workingApp");

    //cpkt->add



    //if (willGeneratePackets) {
    scheduleInterval = par("scheduleInterval");
        cMessage *timer = new cMessage("IPTraffictimer");
        scheduleAt(simTime() + this->scheduleInterval, timer);
    //}

}

void IPTrafficGenerator::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    EV<<"willGeneratePackets = "<<willGeneratePackets<<endl;
    EV<<"numOfFullMTUPackets = "<<numOfFullMTUPackets<<endl;
    EV<<"remainningByteLength = "<<remainningByteLength<<endl;
    if (msg->isSelfMessage()) {


        // delete me start for latency measurement (PingApp)
//        if(numberOfPings){
//            cpkt = new IPv4PacketIB("IPPacket");
//            cpkt->setSourceIP(sourceIP.c_str());
//            cpkt->setDestinationIP(destinationIP.c_str());
//            cpkt->setPayloadLengthInbytes(MTUSize);
//            cpkt->setAppid(this->appid);
//            cpkt->setPacketSequenceNumber(pktSeqNum);
//            pktSeqNum++;
//            cpkt->addByteLength(this->numberOfBytesToSend);
//            send(cpkt->dup(), "ToLowerLayer");
//            numberOfPings--;
//
//            // trigger next event
//            delete msg;
//            cMessage *timer = new cMessage("IPTraffictimer");
//            scheduleAt(simTime() + abs(normal(0,0.1)), timer);
//        }
        // delete me end for latency measurement (PingApp)

        if (numOfFullMTUPackets) {
            // message is not yet transmitted
            cpkt = new IPv4PacketIBS("IPPacket");
            cpkt->setSourceIP(sourceIP.c_str());
            cpkt->setDestinationIP(destinationIP.c_str());
            cpkt->setPayloadLengthInbytes(MTUSize);
            cpkt->setAppid(this->appid);
            cpkt->setPacketSequenceNumber(pktSeqNum);
            cpkt->setTimestamp(simTime());
            pktSeqNum++;
            cpkt->addByteLength(this->MTUSize);
            send(cpkt->dup(), "ToLowerLayer");

            numOfFullMTUPackets--;
            // trigger next event
            cMessage *timer = new cMessage("IPTraffictimer");
            scheduleAt(simTime() + this->scheduleInterval, timer);
        }else{
            if(!remainingBytesSent){
                //send the remaining bytes
                cpkt = new IPv4PacketIBS("IPPacket");
                cpkt->setSourceIP(sourceIP.c_str());
                cpkt->setDestinationIP(destinationIP.c_str());
                cpkt->setPayloadLengthInbytes(MTUSize);
                cpkt->setAppid(this->appid);
                cpkt->setPacketSequenceNumber(pktSeqNum);
                pktSeqNum++;
                cpkt->addByteLength(this->remainningByteLength);
                send(cpkt->dup(), "ToLowerLayer");

                remainingBytesSent = true;
            }
        }


    }
}
