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

#ifndef __TOTFGATEWAYVTHREE_IPOIBLAYER_H_
#define __TOTFGATEWAYVTHREE_IPOIBLAYER_H_

#include <csimplemodule.h>
#include <IBHardWAddress.h>
#include <opp_string.h>
#include <map>
#include <string>
#include <IPv4PacketIBS_m.h>



class IPv4ARPTotf;

class QPsendCompletion;

class cPacketQueue;

class IPoIBFrameIB;
class IPv4PacketIB;

class IPoIBFrame;

class IPv4PacketOnly;

/**
 * TODO - Generated class
 */
class IPoIBLayer : public cSimpleModule
{
public:
    cPacketQueue *ipQUeue;
    IPv4PacketIBS *tempIPPacket;
    IPv4PacketIBS *tempRecvIPPacket;
    IPoIBFrameIB *tempIPoIBFrame;
    IPoIBFrameIB *tempIPoIBARPRequest;
    IPoIBFrameIB *tempIPoIBARPReply;
    IPv4ARPTotf *tempIPARP;
    IPv4ARPTotf *tempIPARPRequest;
    IPv4ARPTotf *tempIPARPReply;
    IBHardWAddress *tempIBHWAddress;
    QPsendCompletion *tempQPCompletionStat;
    std::map<std::string,IBHardWAddress *> IPoIBARPCache;
    std::map<std::string,IBHardWAddress *>::iterator IPoIBARPCacheIterator;

    std::map<std::string,bool> ARPRequestedCache;
    std::map<std::string,bool>::iterator ARPRequestedCacheIterator;
    cMessage *timer;
    int LocalNodeLID;
    int LocalNodePKey;
    opp_string sourceIP;
    int broadcastLID;
    int broadcastPkey;
    int QueuePairBuffSize;
    double scheduleInterval;

    // New Introduced codes For correcting QoS values start
    cPacketQueue *ipQUeueForQoS[16];
    // New Introduced codes For correcting QoS values end

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual int generateSL();
    virtual void finish();
};

#endif
