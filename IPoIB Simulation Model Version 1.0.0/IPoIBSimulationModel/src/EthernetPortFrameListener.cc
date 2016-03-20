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
#include <csimulation.h>
#include <EtherFrameWithQTag_m.h>
#include <EthernetPortFrameListener.h>
#include <IPv4PacketIBS_m.h>
#include <simtime.h>

EthernetPortFrameListener::EthernetPortFrameListener() {
    // TODO Auto-generated constructor stub
    for(int i=0;i<15;i++){
        LatencyPriority[i] = 0.0;
    }

}

EthernetPortFrameListener::~EthernetPortFrameListener() {
    // TODO Auto-generated destructor stub
}

void EthernetPortFrameListener::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj){

     tempEthernetFrame = dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag *>(obj)->dup();
     tempIPv4Packet = dynamic_cast<IPv4PacketIBS *>(tempEthernetFrame->decapsulate());
    // tempIPv4Packet = dynamic_cast<IPv4PacketIBS *>(tempEthernetFrame->dup()->decapsulate());
     appID = tempIPv4Packet->getAppid();

     LatencyPriority[appID] = LatencyPriority[appID] + simTime().dbl() - tempIPv4Packet->getCreationTime().dbl();

   //  delete tempEthernetFrame;
   //  delete tempIPv4Packet;
}
