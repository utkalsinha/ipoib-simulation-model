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

#ifndef ETHERNETPORTFRAMELISTENER_H_
#define ETHERNETPORTFRAMELISTENER_H_



#include <clistener.h>

class IPv4PacketIBS;

namespace CoRE4INET {
class EthernetIIFrameWithQTag;
} /* namespace CoRE4INET */

class EthernetPortFrameListener : public cListener{
public:
    int appID;
    double LatencyPriority[16];
    CoRE4INET::EthernetIIFrameWithQTag *tempEthernetFrame;
    IPv4PacketIBS * tempIPv4Packet;
public:
    EthernetPortFrameListener();
    virtual ~EthernetPortFrameListener();
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj);
};

#endif /* ETHERNETPORTFRAMELISTENER_H_ */
