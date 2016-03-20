//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4PacketOnly.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "IPv4PacketOnly_m.h"

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

Register_Class(IPv4PacketOnly);

IPv4PacketOnly::IPv4PacketOnly(const char *name, int kind) : ::cMessage(name,kind)
{
    this->SourceIP_var = 0;
    this->DestinationIP_var = 0;
    this->payloadLengthInbytes_var = 0;
    this->packetSequenceNumber_var = 0;
}

IPv4PacketOnly::IPv4PacketOnly(const IPv4PacketOnly& other) : ::cMessage(other)
{
    copy(other);
}

IPv4PacketOnly::~IPv4PacketOnly()
{
}

IPv4PacketOnly& IPv4PacketOnly::operator=(const IPv4PacketOnly& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void IPv4PacketOnly::copy(const IPv4PacketOnly& other)
{
    this->SourceIP_var = other.SourceIP_var;
    this->DestinationIP_var = other.DestinationIP_var;
    this->payloadLengthInbytes_var = other.payloadLengthInbytes_var;
    this->packetSequenceNumber_var = other.packetSequenceNumber_var;
}

void IPv4PacketOnly::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->SourceIP_var);
    doPacking(b,this->DestinationIP_var);
    doPacking(b,this->payloadLengthInbytes_var);
    doPacking(b,this->packetSequenceNumber_var);
}

void IPv4PacketOnly::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->SourceIP_var);
    doUnpacking(b,this->DestinationIP_var);
    doUnpacking(b,this->payloadLengthInbytes_var);
    doUnpacking(b,this->packetSequenceNumber_var);
}

const char * IPv4PacketOnly::getSourceIP() const
{
    return SourceIP_var.c_str();
}

void IPv4PacketOnly::setSourceIP(const char * SourceIP)
{
    this->SourceIP_var = SourceIP;
}

const char * IPv4PacketOnly::getDestinationIP() const
{
    return DestinationIP_var.c_str();
}

void IPv4PacketOnly::setDestinationIP(const char * DestinationIP)
{
    this->DestinationIP_var = DestinationIP;
}

int IPv4PacketOnly::getPayloadLengthInbytes() const
{
    return payloadLengthInbytes_var;
}

void IPv4PacketOnly::setPayloadLengthInbytes(int payloadLengthInbytes)
{
    this->payloadLengthInbytes_var = payloadLengthInbytes;
}

int IPv4PacketOnly::getPacketSequenceNumber() const
{
    return packetSequenceNumber_var;
}

void IPv4PacketOnly::setPacketSequenceNumber(int packetSequenceNumber)
{
    this->packetSequenceNumber_var = packetSequenceNumber;
}

class IPv4PacketOnlyDescriptor : public cClassDescriptor
{
  public:
    IPv4PacketOnlyDescriptor();
    virtual ~IPv4PacketOnlyDescriptor();

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

Register_ClassDescriptor(IPv4PacketOnlyDescriptor);

IPv4PacketOnlyDescriptor::IPv4PacketOnlyDescriptor() : cClassDescriptor("IPv4PacketOnly", "cMessage")
{
}

IPv4PacketOnlyDescriptor::~IPv4PacketOnlyDescriptor()
{
}

bool IPv4PacketOnlyDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IPv4PacketOnly *>(obj)!=NULL;
}

const char *IPv4PacketOnlyDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IPv4PacketOnlyDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int IPv4PacketOnlyDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *IPv4PacketOnlyDescriptor::getFieldName(void *object, int field) const
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
        "payloadLengthInbytes",
        "packetSequenceNumber",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int IPv4PacketOnlyDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SourceIP")==0) return base+0;
    if (fieldName[0]=='D' && strcmp(fieldName, "DestinationIP")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLengthInbytes")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetSequenceNumber")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IPv4PacketOnlyDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *IPv4PacketOnlyDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int IPv4PacketOnlyDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketOnly *pp = (IPv4PacketOnly *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IPv4PacketOnlyDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketOnly *pp = (IPv4PacketOnly *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceIP());
        case 1: return oppstring2string(pp->getDestinationIP());
        case 2: return long2string(pp->getPayloadLengthInbytes());
        case 3: return long2string(pp->getPacketSequenceNumber());
        default: return "";
    }
}

bool IPv4PacketOnlyDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketOnly *pp = (IPv4PacketOnly *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceIP((value)); return true;
        case 1: pp->setDestinationIP((value)); return true;
        case 2: pp->setPayloadLengthInbytes(string2long(value)); return true;
        case 3: pp->setPacketSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv4PacketOnlyDescriptor::getFieldStructName(void *object, int field) const
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

void *IPv4PacketOnlyDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IPv4PacketOnly *pp = (IPv4PacketOnly *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


