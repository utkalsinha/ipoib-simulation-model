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

#include <cenvir.h>
#include <cobjectfactory.h>
#include <cownedobject.h>
#include <cregistrationlist.h>
#include <IPoIBSink.h>
#include <regmacros.h>
#include <simutil.h>
#include <iostream>

Define_Module(IPoIBSink);

void IPoIBSink::initialize() {
    // TODO - Generated method body
}

void IPoIBSink::handleMessage(cMessage *msg) {
    // TODO - Generated method body
    tempRecvIPPacket = check_and_cast<IPv4PacketIBS *>(msg);
    EV << "IPoIBData Frame received from " << tempRecvIPPacket->getSourceIP()
              << " and pkt sequence number = "
              << tempRecvIPPacket->getPacketSequenceNumber() << endl;

    delete (tempRecvIPPacket);

}
