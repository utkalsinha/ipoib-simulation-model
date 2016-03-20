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

#ifndef __TOTFGATEWAYVTHREE_IPTRAFFICGENERATOR_H_
#define __TOTFGATEWAYVTHREE_IPTRAFFICGENERATOR_H_

#include <csimplemodule.h>
#include <opp_string.h>
#include <IPv4PacketIBS_m.h>


class IPv4PacketOnly;

/**
 * TODO - Generated class
 */
class IPTrafficGenerator : public cSimpleModule
{
    int numberOfBytesToSend;
    int MTUSize;
    opp_string sourceIP;
    opp_string destinationIP;
    opp_string netMask;
    int PayloadLength;
    int numOfFullMTUPackets;
    int remainningByteLength;
    int pktSeqNum;
    int appid;
    bool remainingBytesSent;

    //delete me start
    int numberOfPings;
    // delte me end
   // IPv4PacketIB *cpkt;
    IPv4PacketIBS *cpkt;

    int tcpHeaderSizeInBytes;
    int udpHeaderSizeInBytes;
    int IPv4HeaderSizeInBytes;

    int effectiveIPFragmentSize;
    bool willGeneratePackets;
    double scheduleInterval;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
