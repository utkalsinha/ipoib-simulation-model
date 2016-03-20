//
// Generated file, do not edit! Created by nedtool 4.6 from IPv4ARPTotf.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "IPv4ARPTotf_m.h"

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

Register_Class(IPv4ARPTotf);

IPv4ARPTotf::IPv4ARPTotf(const char *name, int kind) : ::cPacket(name,kind)
{
    this->SourceIP_var = 0;
    this->DestinationIP_var = 0;
}

IPv4ARPTotf::IPv4ARPTotf(const IPv4ARPTotf& other) : ::cPacket(other)
{
    copy(other);
}

IPv4ARPTotf::~IPv4ARPTotf()
{
}

IPv4ARPTotf& IPv4ARPTotf::operator=(const IPv4ARPTotf& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IPv4ARPTotf::copy(const IPv4ARPTotf& other)
{
    this->SourceIP_var = other.SourceIP_var;
    this->DestinationIP_var = other.DestinationIP_var;
}

void IPv4ARPTotf::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->SourceIP_var);
    doPacking(b,this->DestinationIP_var);
}

void IPv4ARPTotf::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->SourceIP_var);
    doUnpacking(b,this->DestinationIP_var);
}

const char * IPv4ARPTotf::getSourceIP() const
{
    return SourceIP_var.c_str();
}

void IPv4ARPTotf::setSourceIP(const char * SourceIP)
{
    this->SourceIP_var = SourceIP;
}

const char * IPv4ARPTotf::getDestinationIP() const
{
    return DestinationIP_var.c_str();
}

void IPv4ARPTotf::setDestinationIP(const char * DestinationIP)
{
    this->DestinationIP_var = DestinationIP;
}

class IPv4ARPTotfDescriptor : public cClassDescriptor
{
  public:
    IPv4ARPTotfDescriptor();
    virtual ~IPv4ARPTotfDescriptor();

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

Register_ClassDescriptor(IPv4ARPTotfDescriptor);

IPv4ARPTotfDescriptor::IPv4ARPTotfDescriptor() : cClassDescriptor("IPv4ARPTotf", "cPacket")
{
}

IPv4ARPTotfDescriptor::~IPv4ARPTotfDescriptor()
{
}

bool IPv4ARPTotfDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IPv4ARPTotf *>(obj)!=NULL;
}

const char *IPv4ARPTotfDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IPv4ARPTotfDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int IPv4ARPTotfDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *IPv4ARPTotfDescriptor::getFieldName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int IPv4ARPTotfDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SourceIP")==0) return base+0;
    if (fieldName[0]=='D' && strcmp(fieldName, "DestinationIP")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IPv4ARPTotfDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *IPv4ARPTotfDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int IPv4ARPTotfDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IPv4ARPTotf *pp = (IPv4ARPTotf *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IPv4ARPTotfDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IPv4ARPTotf *pp = (IPv4ARPTotf *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceIP());
        case 1: return oppstring2string(pp->getDestinationIP());
        default: return "";
    }
}

bool IPv4ARPTotfDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IPv4ARPTotf *pp = (IPv4ARPTotf *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceIP((value)); return true;
        case 1: pp->setDestinationIP((value)); return true;
        default: return false;
    }
}

const char *IPv4ARPTotfDescriptor::getFieldStructName(void *object, int field) const
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

void *IPv4ARPTotfDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IPv4ARPTotf *pp = (IPv4ARPTotf *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


