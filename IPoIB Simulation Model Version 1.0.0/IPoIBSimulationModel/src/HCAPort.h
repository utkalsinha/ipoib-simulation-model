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

#ifndef __TOTFGATEWAYVTHREE_HCAPORT_H_
#define __TOTFGATEWAYVTHREE_HCAPORT_H_

#include <csimplemodule.h>
#include <map>

class IPoIBFrameIB;

class cPacketQueue;

/**
 * TODO - Generated class
 */
class HCAPort : public cSimpleModule
{
    cPacketQueue *vlo[16]; // output virtual lane buffers
    cPacketQueue *vli[16]; // input virtual lane buffers

    std::map<int,int> VLArbitrationTable;
    std::map<int,int>::iterator VLArbitrationTableIterator;

    IPoIBFrameIB *tempIPoIBFrameFromNet;
    IPoIBFrameIB *tempIPoIBFrameFromUpperLayer;
    IPoIBFrameIB *tempVLFrame;

    int vlArbitrationCount[16];

    int bothVLInOutEmptyCOunt;
    int TempVlIndex;
    int portLid;
    int portPkey;
    cMessage *timer;

    double scheduleInterval;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
