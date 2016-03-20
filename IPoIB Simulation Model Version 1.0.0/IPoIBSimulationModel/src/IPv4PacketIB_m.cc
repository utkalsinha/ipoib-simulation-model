//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4PacketIB.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "IPv4PacketIB_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(IPv4PacketIB);

IPv4PacketIB::IPv4PacketIB(const char *name, int kind) : ::cPacket(name,kind)
{
    this->SourceIP_var = 0;
    this->DestinationIP_var = 0;
    this->appid_var = 0;
    this->payloadLengthInbytes_var = 0;
    this->packetSequenceNumber_var = 0;
}

IPv4PacketIB::IPv4PacketIB(const IPv4PacketIB& other) : ::cPacket(other)
{
    copy(other);
}

IPv4PacketIB::~IPv4PacketIB()
{
}

IPv4PacketIB& IPv4PacketIB::operator=(const IPv4PacketIB& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IPv4PacketIB::copy(const IPv4PacketIB& other)
{
    this->SourceIP_var = other.SourceIP_var;
    this->DestinationIP_var = other.DestinationIP_var;
    this->appid_var = other.appid_var;
    this->payloadLengthInbytes_var = other.payloadLengthInbytes_var;
    this->packetSequenceNumber_var = other.packetSequenceNumber_var;
}

void IPv4PacketIB::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->SourceIP_var);
    doPacking(b,this->DestinationIP_var);
    doPacking(b,this->appid_var);
    doPacking(b,this->payloadLengthInbytes_var);
    doPacking(b,this->packetSequenceNumber_var);
}

void IPv4PacketIB::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->SourceIP_var);
    doUnpacking(b,this->DestinationIP_var);
    doUnpacking(b,this->appid_var);
    doUnpacking(b,this->payloadLengthInbytes_var);
    doUnpacking(b,this->packetSequenceNumber_var);
}

const char * IPv4PacketIB::getSourceIP() const
{
    return SourceIP_var.c_str();
}

void IPv4PacketIB::setSourceIP(const char * SourceIP)
{
    this->SourceIP_var = SourceIP;
}

const char * IPv4PacketIB::getDestinationIP() const
{
    return DestinationIP_var.c_str();
}

void IPv4PacketIB::setDestinationIP(const char * DestinationIP)
{
    this->DestinationIP_var = DestinationIP;
}

int IPv4PacketIB::getAppid() const
{
    return appid_var;
}

void IPv4PacketIB::setAppid(int appid)
{
    this->appid_var = appid;
}

int IPv4PacketIB::getPayloadLengthInbytes() const
{
    return payloadLengthInbytes_var;
}

void IPv4PacketIB::setPayloadLengthInbytes(int payloadLengthInbytes)
{
    this->payloadLengthInbytes_var = payloadLengthInbytes;
}

int IPv4PacketIB::getPacketSequenceNumber() const
{
    return packetSequenceNumber_var;
}

void IPv4PacketIB::setPacketSequenceNumber(int packetSequenceNumber)
{
    this->packetSequenceNumber_var = packetSequenceNumber;
}

class IPv4PacketIBDescriptor : public cClassDescriptor
{
  public:
    IPv4PacketIBDescriptor();
    virtual ~IPv4PacketIBDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IPv4PacketIBDescriptor);

IPv4PacketIBDescriptor::IPv4PacketIBDescriptor() : cClassDescriptor("IPv4PacketIB", "cPacket")
{
}

IPv4PacketIBDescriptor::~IPv4PacketIBDescriptor()
{
}

bool IPv4PacketIBDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IPv4PacketIB *>(obj)!=NULL;
}

const char *IPv4PacketIBDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IPv4PacketIBDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int IPv4PacketIBDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *IPv4PacketIBDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "SourceIP",
        "DestinationIP",
        "appid",
        "payloadLengthInbytes",
        "packetSequenceNumber",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int IPv4PacketIBDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SourceIP")==0) return base+0;
    if (fieldName[0]=='D' && strcmp(fieldName, "DestinationIP")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "appid")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLengthInbytes")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetSequenceNumber")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IPv4PacketIBDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *IPv4PacketIBDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IPv4PacketIBDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketIB *pp = (IPv4PacketIB *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IPv4PacketIBDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketIB *pp = (IPv4PacketIB *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceIP());
        case 1: return oppstring2string(pp->getDestinationIP());
        case 2: return long2string(pp->getAppid());
        case 3: return long2string(pp->getPayloadLengthInbytes());
        case 4: return long2string(pp->getPacketSequenceNumber());
        default: return "";
    }
}

bool IPv4PacketIBDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketIB *pp = (IPv4PacketIB *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceIP((value)); return true;
        case 1: pp->setDestinationIP((value)); return true;
        case 2: pp->setAppid(string2long(value)); return true;
        case 3: pp->setPayloadLengthInbytes(string2long(value)); return true;
        case 4: pp->setPacketSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv4PacketIBDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *IPv4PacketIBDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketIB *pp = (IPv4PacketIB *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


