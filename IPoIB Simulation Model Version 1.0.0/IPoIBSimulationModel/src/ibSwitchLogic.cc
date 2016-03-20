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
#include <cownedobject.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <distrib.h>
#include <ibSwitchLogic.h>
#include <IPoIBFrameIB_m.h>
#include <regmacros.h>
#include <simtime.h>
#include <simutil.h>
#include <iostream>
#include <string>
#include <utility>

Define_Module(IbSwitchLogic);

void IbSwitchLogic::initialize() {
    // TODO - Generated method body
    LidPortTable[101] = 1; // format is LID <--> port
    LidPortTable[102] = 2;
    LidPortTable[103] = 3;
    LidPortTable[104] = 4;
    LidPortTable[105] = 5;

    BroadcastLidPkeyTable[201] = 201; // format is broadcast dlid <--> pkey
    BroadcastLidPkeyTable[202] = 202;
    BroadcastLidPkeyTable[203] = 203;
    BroadcastLidPkeyTable[204] = 204;
    BroadcastLidPkeyTable[205] = 205;

    // Assigning InfiniBand partition ports based on pkey
    BDLIDtoPortMappingTable[201].push_back(1);
    BDLIDtoPortMappingTable[201].push_back(2);
    BDLIDtoPortMappingTable[201].push_back(3);
    //BDLIDtoPortMappingTable[201].push_back(5);

    BDLIDtoPortMappingTable[202].push_back(2);
    BDLIDtoPortMappingTable[202].push_back(3);
   // BDLIDtoPortMappingTable[202].push_back(5);

    BDLIDtoPortMappingTable[203].push_back(1);
    BDLIDtoPortMappingTable[203].push_back(5);

    BDLIDtoPortMappingTable[204].push_back(1);
    BDLIDtoPortMappingTable[204].push_back(2);
    BDLIDtoPortMappingTable[204].push_back(3);
    BDLIDtoPortMappingTable[204].push_back(4);
   // BDLIDtoPortMappingTable[204].push_back(5);

    BDLIDtoPortMappingTable[205].push_back(2);
    BDLIDtoPortMappingTable[205].push_back(3);
    BDLIDtoPortMappingTable[205].push_back(4);

    // for latency calculation for one hop
    numberOfPacketsReceived = 0;


    SwitchinterportLatency = par("switchingLatency");
}

void IbSwitchLogic::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    if (msg->isSelfMessage()) {
        // self triggered. Check for events it has to genereate

    } else if (msg->arrivedOn("fromPort1")) {
        // message arrived on switch port 1
        tempIPoIBFrame = dynamic_cast<IPoIBFrameIB *>(msg);

        if (checkForBroadcastFrame(tempIPoIBFrame->getDLid())) {
            // broadcast the received IPoIB Frame
            std::ostringstream ssb;

            int BDLIDtoPortMappingTableindex = tempIPoIBFrame->getDLid();
            unsigned int numOfPortsInThisBroadcastDomain =
                    this->BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex].size();

            for (unsigned int i = 0; i < numOfPortsInThisBroadcastDomain; i++) {
                ssb.str( { });
                ssb << BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i];
                // this condition is to stop broadcasting to the source LID. Or Packet Looping.
                if (BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i]
                        != LidPortTable[tempIPoIBFrame->getSLid()]) {
                    std::string tempStringB = "toPort" + ssb.str();
                    // (i+1) to avoid last frame duplicate
                    if ((i + 1) == numOfPortsInThisBroadcastDomain) {
                        sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempStringB.c_str());
                    } else {
                        sendDelayed(tempIPoIBFrame->dup(),this->SwitchinterportLatency, tempStringB.c_str());
                    }
                }
            }

        } else {
            // Forward the received IPoIB Frame to the appropriate switch port
            int forwardingPort = getSwitchPort(tempIPoIBFrame->getDLid());
            if (forwardingPort >= 0) {
                //valid port found. Forward the received IPoIBFrame
                std::ostringstream ss;
                ss.str( { });
                ss << forwardingPort;
                std::string tempString = "toPort" + ss.str();

                sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempString.c_str());
            }

        }

    } else if (msg->arrivedOn("fromPort2")) {
        // message arrived on switch port 1
        tempIPoIBFrame = dynamic_cast<IPoIBFrameIB *>(msg);
        if (checkForBroadcastFrame(tempIPoIBFrame->getDLid())) {
            // broadcast the received IPoIB Frame
            std::ostringstream ssb;

            int BDLIDtoPortMappingTableindex = tempIPoIBFrame->getDLid();
            unsigned int numOfPortsInThisBroadcastDomain =
                    this->BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex].size();

            for (unsigned int i = 0; i < numOfPortsInThisBroadcastDomain; i++) {
                ssb.str( { });
                ssb << BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i];
                // this condition is to stop broadcasting to the source LID. Or Packet Looping.
                if (BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i]
                        != LidPortTable[tempIPoIBFrame->getSLid()]) {
                    std::string tempStringB = "toPort" + ssb.str();
                    // (i+1) to avoid last frame duplicate
                    if ((i + 1) == numOfPortsInThisBroadcastDomain) {
                        sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempStringB.c_str());
                    } else {
                        sendDelayed(tempIPoIBFrame->dup(),this->SwitchinterportLatency, tempStringB.c_str());
                    }
                }
            }

        } else {
            // Forward the received IPoIB Frame to the appropriate switch port
            int forwardingPort = getSwitchPort(tempIPoIBFrame->getDLid());
            if (forwardingPort >= 0) {
                //valid port found. Forward the received IPoIBFrame
                std::ostringstream ss;
                ss.str( { });
                ss << forwardingPort;
                std::string tempString = "toPort" + ss.str();

                sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempString.c_str());
            }

        }

    } else if (msg->arrivedOn("fromPort3")) {
        // message arrived on switch port 1
        // Delete me Start
        EV<<"==================> Message arrived fromPort3"<<endl;
        // Delete me ends

        tempIPoIBFrame = dynamic_cast<IPoIBFrameIB *>(msg);
        if (checkForBroadcastFrame(tempIPoIBFrame->getDLid())) {
            // broadcast the received IPoIB Frame
            std::ostringstream ssb;

            int BDLIDtoPortMappingTableindex = tempIPoIBFrame->getDLid();
            unsigned int numOfPortsInThisBroadcastDomain =
                    this->BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex].size();

            for (unsigned int i = 0; i < numOfPortsInThisBroadcastDomain; i++) {
                ssb.str( { });
                ssb << BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i];
                // this condition is to stop broadcasting to the source LID. Or Packet Looping.
                if (BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i]
                        != LidPortTable[tempIPoIBFrame->getSLid()]) {
                    std::string tempStringB = "toPort" + ssb.str();
                    // (i+1) to avoid last frame duplicate

                    //Delete me start
                    EV
                              << "IB Switch Logic Received frame fromPort3. BDLIDtoPortMappingTableindex = "
                              << BDLIDtoPortMappingTableindex
                              << " and is forwarded to " << tempStringB << endl;
                    //Delete me ends
                    if ((i + 1) == numOfPortsInThisBroadcastDomain) {
                        sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempStringB.c_str());
                    } else {
                        sendDelayed(tempIPoIBFrame->dup(),this->SwitchinterportLatency, tempStringB.c_str());
                    }
                }
            }

        } else {
            // Forward the received IPoIB Frame to the appropriate switch port
            int forwardingPort = getSwitchPort(tempIPoIBFrame->getDLid());
            if (forwardingPort >= 0) {
                //valid port found. Forward the received IPoIBFrame
                std::ostringstream ss;
                ss.str( { });
                ss << forwardingPort;
                std::string tempString = "toPort" + ss.str();

                sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempString.c_str());
            }

        }

    } else if (msg->arrivedOn("fromPort4")) {
        // message arrived on switch port 1
        tempIPoIBFrame = dynamic_cast<IPoIBFrameIB *>(msg);
        if (checkForBroadcastFrame(tempIPoIBFrame->getDLid())) {
            // broadcast the received IPoIB Frame
            std::ostringstream ssb;

            int BDLIDtoPortMappingTableindex = tempIPoIBFrame->getDLid();
            unsigned int numOfPortsInThisBroadcastDomain =
                    this->BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex].size();

            for (unsigned int i = 0; i < numOfPortsInThisBroadcastDomain; i++) {
                ssb.str( { });
                ssb << BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i];
                // this condition is to stop broadcasting to the source LID. Or Packet Looping.
                if (BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i]
                        != LidPortTable[tempIPoIBFrame->getSLid()]) {
                    std::string tempStringB = "toPort" + ssb.str();
                    // (i+1) to avoid last frame duplicate
                    if ((i + 1) == numOfPortsInThisBroadcastDomain) {
                        sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempStringB.c_str());
                    } else {
                        sendDelayed(tempIPoIBFrame->dup(),this->SwitchinterportLatency, tempStringB.c_str());
                    }
                }
            }

        } else {
            // Forward the received IPoIB Frame to the appropriate switch port
            int forwardingPort = getSwitchPort(tempIPoIBFrame->getDLid());
            if (forwardingPort >= 0) {
                //valid port found. Forward the received IPoIBFrame
                std::ostringstream ss;
                ss.str( { });
                ss << forwardingPort;
                std::string tempString = "toPort" + ss.str();

                sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempString.c_str());
            }

        }

    } else if (msg->arrivedOn("fromPort5")) {
        // message arrived on switch port 1
        tempIPoIBFrame = dynamic_cast<IPoIBFrameIB *>(msg);
        if (checkForBroadcastFrame(tempIPoIBFrame->getDLid())) {
            // broadcast the received IPoIB Frame
            std::ostringstream ssb;

            int BDLIDtoPortMappingTableindex = tempIPoIBFrame->getDLid();
            unsigned int numOfPortsInThisBroadcastDomain =
                    this->BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex].size();

            for (unsigned int i = 0; i < numOfPortsInThisBroadcastDomain; i++) {
                ssb.str( { });
                ssb << BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i];
                // this condition is to stop broadcasting to the source LID. Or Packet Looping.
                if (BDLIDtoPortMappingTable[BDLIDtoPortMappingTableindex][i]
                        != LidPortTable[tempIPoIBFrame->getSLid()]) {
                    std::string tempStringB = "toPort" + ssb.str();
                    // (i+1) to avoid last frame duplicate
                    if ((i + 1) == numOfPortsInThisBroadcastDomain) {
                        sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempStringB.c_str());
                    } else {
                        sendDelayed(tempIPoIBFrame->dup(),this->SwitchinterportLatency, tempStringB.c_str());
                    }
                }
            }

        } else {
            // Forward the received IPoIB Frame to the appropriate switch port
            int forwardingPort = getSwitchPort(tempIPoIBFrame->getDLid());
            if (forwardingPort >= 0) {
                //valid port found. Forward the received IPoIBFrame
                std::ostringstream ss;
                ss.str( { });
                ss << forwardingPort;
                std::string tempString = "toPort" + ss.str();

                sendDelayed(tempIPoIBFrame,this->SwitchinterportLatency, tempString.c_str());
            }

        }

    }
}

bool IbSwitchLogic::checkForBroadcastFrame(int lid) {
    BroadcastLidPkeyTableIterator = BroadcastLidPkeyTable.find(lid);
    if (BroadcastLidPkeyTableIterator == BroadcastLidPkeyTable.end()) {
        // dlid not found in the broadcast mapping table. So the dlid is not a broadcast lid. So return false;
        return false;
    } else {
        // dlid is found in the lid pkey broadcast mapping table. so return true;
        return true;
    }
}

int IbSwitchLogic::getSwitchPort(int lid) {
    LidPortTableIterator = LidPortTable.find(lid);
    if (LidPortTableIterator == LidPortTable.end()) {
        //Lid not found. Send the invalid port number (-1)
        return -1;
    } else {
        //Lid found. Send the corresponting port number
        return LidPortTableIterator->second;
    }

}

void IbSwitchLogic::finish() {
 //   double tempTotallatency = 0;
 //   for (int i = 0; i < numberOfPacketsReceived; i++) {
 //       tempTotallatency = tempTotallatency + OnewayLatency[i];
 //   }
 //   tempTotallatency = tempTotallatency/numberOfPacketsReceived;
 //   recordScalar("Average switch one way latency", tempTotallatency);

}
