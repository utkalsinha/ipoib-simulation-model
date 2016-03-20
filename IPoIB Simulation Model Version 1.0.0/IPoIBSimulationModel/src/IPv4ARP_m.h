//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4ARP.msg.
//

#ifndef _IPV4ARP_M_H_
#define _IPV4ARP_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>IPv4ARP.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet IPv4ARP
 * {
 *     string SourceIP;
 *     string DestinationIP;
 * }
 * </pre>
 */
class IPv4ARP : public ::cPacket
{
  protected:
    opp_string SourceIP_var;
    opp_string DestinationIP_var;

  private:
    void copy(const IPv4ARP& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv4ARP&);

  public:
    IPv4ARP(const char *name=NULL, int kind=0);
    IPv4ARP(const IPv4ARP& other);
    virtual ~IPv4ARP();
    IPv4ARP& operator=(const IPv4ARP& other);
    virtual IPv4ARP *dup() const {return new IPv4ARP(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getSourceIP() const;
    virtual void setSourceIP(const char * SourceIP);
    virtual const char * getDestinationIP() const;
    virtual void setDestinationIP(const char * DestinationIP);
};

inline void doPacking(cCommBuffer *b, IPv4ARP& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv4ARP& obj) {obj.parsimUnpack(b);}


#endif // ifndef _IPV4ARP_M_H_

