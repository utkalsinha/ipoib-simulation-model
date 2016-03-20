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
#include <cqueue.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <distrib.h>
#include <IPoIBFrameIB_m.h>
#include <QPsendCompletion_m.h>
#include <QueuePair.h>
#include <regmacros.h>
#include <simtime.h>
#include <simutil.h>
#include <stddef.h>

Define_Module(QueuePair);

void QueuePair::initialize()
{
    // TODO - Generated method body
    ipoibSendQUeue = new cPacketQueue(NULL, NULL);
    ipoibRecvQUeue = new cPacketQueue(NULL, NULL);

    scheduleInterval = par("scheduleInterval");
    timer = new cMessage("QueuePairTimer");
    scheduleAt(simTime() + this->scheduleInterval, timer);
}

void QueuePair::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage()){
        // current module triggered. Check for sending opportunities (from SendQueue to HCA VL or from Recv Queue to IPoIB Layer)
        // {Coding stat: pending}
        if(!ipoibRecvQUeue->isEmpty()){
            // Receive queue is not empty. Forward the received frame to upper IPoIB Layer
            send(ipoibRecvQUeue->pop(),"fromBelowRecvQToIPoIBLayer");
        }
        if(!ipoibSendQUeue->isEmpty()){
            // outstanding IPoIBFrames are there. Send the next one.
            send(ipoibSendQUeue->pop(),"toBelowHCAVL");
            tempSendQCompletionStat = new QPsendCompletion("QPCompletionStat");
            tempSendQCompletionStat->setSendSuccessStat(true);
            send(tempSendQCompletionStat->dup(),"fromBelowCompletionQToIPoIBLayerStat");
        }

        // trigger next self event
        delete msg;
        timer = new cMessage("QueuePairTimer");
        scheduleAt(simTime() + this->scheduleInterval, timer);
    }
    else if(msg->arrivedOn("fromIPoIBLayer")){
        // IPoIB frame from the IPoIB Layer. Queue it in SendQueue. {Coding stat: done}
        TempipoibFrameFromIPoIBLayer = dynamic_cast<IPoIBFrameIB *>(msg);

        ipoibSendQUeue->insert(TempipoibFrameFromIPoIBLayer->dup());
    }
    else if(msg->arrivedOn("fromBelowVLtoRecdQ")){
        // IPoIB frame is received from the HCA virtual lanes. Queue it in Receive Queue. {Coding stat: done}
        TempipoibFrameFromIPoIBLayer = dynamic_cast<IPoIBFrameIB *>(msg);
        ipoibRecvQUeue->insert(TempipoibFrameFromIPoIBLayer->dup());
    }
}
