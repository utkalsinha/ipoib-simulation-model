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

#include <cmodule.h>
#include <csimulation.h>
#include <MyFrameListener.h>
#include <cstring>

MyFrameListener::MyFrameListener() {
    // TODO Auto-generated constructor stub
    this->tempDelmeJustForTest = 0;
    for(int i=0;i<15;i++){
        LatencyPriority[i] = 0.0;
    }
}

MyFrameListener::~MyFrameListener() {
    // TODO Auto-generated destructor stub
}

void MyFrameListener::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj){
    //Frame listening receiving Signal. Monitor the received signal
    //EV <<"Signal received ================================================="<<endl;

    //if(strcmp(simulation.getSystemModule()->getSignalName(signalID), "packetReceivedFromLower") == 0)
        tempDelmeJustForTest++;
 //   LatencyPriority[15] = LatencyPriority[15] + simTime().dbl() -
       // signalIDArray[index] = signalID;
       // index++;
}

