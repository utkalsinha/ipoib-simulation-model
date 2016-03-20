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
#include <cpacketqueue.h>
#include <cpar.h>
#include <cqueue.h>
#include <cregistrationlist.h>
#include <HCAPort.h>
#include <IPoIBFrameIB_m.h>
#include <regmacros.h>
#include <simutil.h>

Define_Module(HCAPort);

void HCAPort::initialize() {
    // TODO - Generated method body
    for (int i = 0; i < 16; i++) {
        vlo[i] = new cPacketQueue(NULL, NULL);
        vli[i] = new cPacketQueue(NULL, NULL);
    }

    // fill the VL Arbitration Table
//    for(int i=0;i<16;i++)
//        VLArbitrationTable[i] = par("vl0weight"+i);
    vlArbitrationCount[0] = VLArbitrationTable[0] = par("vl0weight");
    vlArbitrationCount[1] = VLArbitrationTable[1] = par("vl1weight");
    vlArbitrationCount[2] = VLArbitrationTable[2] = par("vl2weight");
    vlArbitrationCount[3] = VLArbitrationTable[3] = par("vl3weight");
    vlArbitrationCount[4] = VLArbitrationTable[4] = par("vl4weight");
    vlArbitrationCount[5] = VLArbitrationTable[5] = par("vl5weight");
    vlArbitrationCount[6] = VLArbitrationTable[6] = par("vl6weight");
    vlArbitrationCount[7] = VLArbitrationTable[7] = par("vl7weight");
    vlArbitrationCount[8] = VLArbitrationTable[8] = par("vl8weight");
    vlArbitrationCount[9] = VLArbitrationTable[9] = par("vl9weight");
    vlArbitrationCount[10] = VLArbitrationTable[10] = par("vl10weight");
    vlArbitrationCount[11] = VLArbitrationTable[11] = par("vl11weight");
    vlArbitrationCount[12] = VLArbitrationTable[12] = par("vl12weight");
    vlArbitrationCount[13] = VLArbitrationTable[13] = par("vl13weight");
    vlArbitrationCount[14] = VLArbitrationTable[14] = par("vl14weight");
    vlArbitrationCount[15] = VLArbitrationTable[15] = par("vl15weight");

    portLid = par("portLID");
    portPkey = par("portPkey");
    scheduleInterval = par("scheduleInterval");
    timer = new cMessage("HCAPortTimer");
    scheduleAt(simTime() + this->scheduleInterval, timer);
}

void HCAPort::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    if (msg->isSelfMessage()) {
        // self module triggered. Send from to net or to above layers based on vl arbitration table

// for VL 15
        for (int i = 15; i >= 0; i--) {
            for (int j = 0; j < vlArbitrationCount[i]; j++) {
                bothVLInOutEmptyCOunt = 0;
                if (!vlo[i]->isEmpty()) {
                    tempVLFrame = dynamic_cast<IPoIBFrameIB *>(vlo[i]->pop());
                    cGate *outGate = gate("netport$o");
                    if(outGate->getTransmissionChannel()->isBusy()){
                        simtime_t serialTime = outGate->getTransmissionChannel()->getTransmissionFinishTime();
                       // scheduleAt(simTime() + outGate->getTransmissionChannel()->getTransmissionFinishTime(),tempVLFrame);
                        sendDelayed(tempVLFrame,simTime()+serialTime, "netport$o");
                    }else{
                        send(tempVLFrame, "netport$o");
                    }
                } else
                    bothVLInOutEmptyCOunt++;
                if (!vli[i]->isEmpty()) {
                    tempVLFrame = dynamic_cast<IPoIBFrameIB *>(vli[i]->pop());
                    send(tempVLFrame, "toUpperLayer");
                } else {
                    if (bothVLInOutEmptyCOunt)
                        break;
                }

            }
        }

        delete msg;
        timer = new cMessage("HCAPortTimer");
        scheduleAt(simTime() + this->scheduleInterval, timer);

    } else if (msg->arrivedOn("fromUpperLayer")) {
        // packets received from Upper Layer. Queue it to suitable VL buffer based on VL id inside the packet.
        tempIPoIBFrameFromUpperLayer = dynamic_cast<IPoIBFrameIB *>(msg);
        switch (tempIPoIBFrameFromUpperLayer->getVl()) {
        case 0:
            vlo[0]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 1:
            vlo[1]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 2:
            vlo[2]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 3:
            vlo[3]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 4:
            vlo[4]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 5:
            vlo[5]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 6:
            vlo[6]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 7:
            vlo[7]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 8:
            vlo[8]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 9:
            vlo[9]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 10:
            vlo[10]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 11:
            vlo[11]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 12:
            vlo[12]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 13:
            vlo[13]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 14:
            vlo[14]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        case 15:
            vlo[15]->insert(tempIPoIBFrameFromUpperLayer);
            break;
        };

    } else if (msg->arrivedOn("netport$i")) {
        // received a network IPoIB Frame. Enqueue it to suitable VL buffer
        tempIPoIBFrameFromNet = dynamic_cast<IPoIBFrameIB *>(msg);
        switch (tempIPoIBFrameFromNet->getVl()) {
        case 0:
            vli[0]->insert(tempIPoIBFrameFromNet);
            break;
        case 1:
            vli[1]->insert(tempIPoIBFrameFromNet);
            break;
        case 2:
            vli[2]->insert(tempIPoIBFrameFromNet);
            break;
        case 3:
            vli[3]->insert(tempIPoIBFrameFromNet);
            break;
        case 4:
            vli[4]->insert(tempIPoIBFrameFromNet);
            break;
        case 5:
            vli[5]->insert(tempIPoIBFrameFromNet);
            break;
        case 6:
            vli[6]->insert(tempIPoIBFrameFromNet);
            break;
        case 7:
            vli[7]->insert(tempIPoIBFrameFromNet);
            break;
        case 8:
            vli[8]->insert(tempIPoIBFrameFromNet);
            break;
        case 9:
            vli[9]->insert(tempIPoIBFrameFromNet);
            break;
        case 10:
            vli[10]->insert(tempIPoIBFrameFromNet);
            break;
        case 11:
            vli[11]->insert(tempIPoIBFrameFromNet);
            break;
        case 12:
            vli[12]->insert(tempIPoIBFrameFromNet);
            break;
        case 13:
            vli[13]->insert(tempIPoIBFrameFromNet);
            break;
        case 14:
            vli[14]->insert(tempIPoIBFrameFromNet);
            break;
        case 15:
            vli[15]->insert(tempIPoIBFrameFromNet);
            break;
        };
    }
}
