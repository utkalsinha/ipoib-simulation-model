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

#ifndef __TOTFGATEWAYVTHREE_QUEUEPAIR_H_
#define __TOTFGATEWAYVTHREE_QUEUEPAIR_H_

#include <csimplemodule.h>

class QPsendCompletion;

class cPacketQueue;
class IPoIBFrameIB;

/**
 * TODO - Generated class
 */
class QueuePair : public cSimpleModule
{
    cPacketQueue *ipoibSendQUeue;
    cPacketQueue *ipoibRecvQUeue;
    IPoIBFrameIB *TempipoibFrameFromIPoIBLayer;
    QPsendCompletion *tempSendQCompletionStat;

    cMessage *timer;
    double scheduleInterval;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
