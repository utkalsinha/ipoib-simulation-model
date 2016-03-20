//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4PacketIB.msg.
//

#ifndef _IPV4PACKETIB_M_H_
#define _IPV4PACKETIB_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>IPv4PacketIB.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet IPv4PacketIB
 * {
 *     string SourceIP;
 *     string DestinationIP;
 *     int appid;
 *     int payloadLengthInbytes;
 *     int packetSequenceNumber;
 * }
 * </pre>
 */
class IPv4PacketIB : public ::cPacket
{
  protected:
    opp_string SourceIP_var;
    opp_string DestinationIP_var;
    int appid_var;
    int payloadLengthInbytes_var;
    int packetSequenceNumber_var;

  private:
    void copy(const IPv4PacketIB& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv4PacketIB&);

  public:
    IPv4PacketIB(const char *name=NULL, int kind=0);
    IPv4PacketIB(const IPv4PacketIB& other);
    virtual ~IPv4PacketIB();
    IPv4PacketIB& operator=(const IPv4PacketIB& other);
    virtual IPv4PacketIB *dup() const {return new IPv4PacketIB(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getSourceIP() const;
    virtual void setSourceIP(const char * SourceIP);
    virtual const char * getDestinationIP() const;
    virtual void setDestinationIP(const char * DestinationIP);
    virtual int getAppid() const;
    virtual void setAppid(int appid);
    virtual int getPayloadLengthInbytes() const;
    virtual void setPayloadLengthInbytes(int payloadLengthInbytes);
    virtual int getPacketSequenceNumber() const;
    virtual void setPacketSequenceNumber(int packetSequenceNumber);
};

inline void doPacking(cCommBuffer *b, IPv4PacketIB& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv4PacketIB& obj) {obj.parsimUnpack(b);}


#endif // ifndef _IPV4PACKETIB_M_H_
