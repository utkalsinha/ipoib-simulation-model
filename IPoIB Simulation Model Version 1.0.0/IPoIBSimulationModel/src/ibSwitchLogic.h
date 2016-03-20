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

#ifndef __TOTFGATEWAYVTHREE_IBSWITCHLOGIC_H_
#define __TOTFGATEWAYVTHREE_IBSWITCHLOGIC_H_

#include <csimplemodule.h>
#include <map>
#include <vector>

class IPoIBFrameIB;



/**
 * TODO - Generated class
 */
class IbSwitchLogic: public cSimpleModule {

    cMessage *timer;
    std::map<int, int> LidPortTable;
    std::map<int, int>::iterator LidPortTableIterator;

    std::map<int, int> BroadcastLidPkeyTable;
    std::map<int, int>::iterator BroadcastLidPkeyTableIterator;

    std::vector<int> BDLIDtoPortMappingTable[65536]; // 16 bit Pkey will have 2^16 = 65536
    IPoIBFrameIB *tempIPoIBFrame;

    // delete me variable
    double SwitchinterportLatency;
    // delete me variable end

    // For recording results
    double OnewayLatency[16];
    int numberOfPacketsReceived;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual bool checkForBroadcastFrame(int lid);
    virtual int getSwitchPort(int lid);
    virtual void finish();
};

#endif
