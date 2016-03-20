//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4PacketOnly.msg.
//

#ifndef _IPV4PACKETONLY_M_H_
#define _IPV4PACKETONLY_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>IPv4PacketOnly.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message IPv4PacketOnly
 * {
 *     string SourceIP;
 *     string DestinationIP;
 *     int payloadLengthInbytes;
 *     int packetSequenceNumber;
 * }
 * </pre>
 */
class IPv4PacketOnly : public ::cMessage
{
  protected:
    opp_string SourceIP_var;
    opp_string DestinationIP_var;
    int payloadLengthInbytes_var;
    int packetSequenceNumber_var;

  private:
    void copy(const IPv4PacketOnly& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv4PacketOnly&);

  public:
    IPv4PacketOnly(const char *name=NULL, int kind=0);
    IPv4PacketOnly(const IPv4PacketOnly& other);
    virtual ~IPv4PacketOnly();
    IPv4PacketOnly& operator=(const IPv4PacketOnly& other);
    virtual IPv4PacketOnly *dup() const {return new IPv4PacketOnly(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getSourceIP() const;
    virtual void setSourceIP(const char * SourceIP);
    virtual const char * getDestinationIP() const;
    virtual void setDestinationIP(const char * DestinationIP);
    virtual int getPayloadLengthInbytes() const;
    virtual void setPayloadLengthInbytes(int payloadLengthInbytes);
    virtual int getPacketSequenceNumber() const;
    virtual void setPacketSequenceNumber(int packetSequenceNumber);
};

inline void doPacking(cCommBuffer *b, IPv4PacketOnly& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv4PacketOnly& obj) {obj.parsimUnpack(b);}


#endif // ifndef _IPV4PACKETONLY_M_H_

