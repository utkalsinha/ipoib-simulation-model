//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4ARPTotf.msg.
//

#ifndef _IPV4ARPTOTF_M_H_
#define _IPV4ARPTOTF_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>IPv4ARPTotf.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet IPv4ARPTotf
 * {
 *     string SourceIP;
 *     string DestinationIP;
 * }
 * </pre>
 */
class IPv4ARPTotf : public ::cPacket
{
  protected:
    opp_string SourceIP_var;
    opp_string DestinationIP_var;

  private:
    void copy(const IPv4ARPTotf& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv4ARPTotf&);

  public:
    IPv4ARPTotf(const char *name=NULL, int kind=0);
    IPv4ARPTotf(const IPv4ARPTotf& other);
    virtual ~IPv4ARPTotf();
    IPv4ARPTotf& operator=(const IPv4ARPTotf& other);
    virtual IPv4ARPTotf *dup() const {return new IPv4ARPTotf(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getSourceIP() const;
    virtual void setSourceIP(const char * SourceIP);
    virtual const char * getDestinationIP() const;
    virtual void setDestinationIP(const char * DestinationIP);
};

inline void doPacking(cCommBuffer *b, IPv4ARPTotf& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv4ARPTotf& obj) {obj.parsimUnpack(b);}


#endif // ifndef _IPV4ARPTOTF_M_H_
