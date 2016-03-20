//
// Generated file, do not edit! Created by nedtool 4.6 from IPoIBFrameIB.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "IPoIBFrameIB_m.h"

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

Register_Class(IPoIBFrameIB);

IPoIBFrameIB::IPoIBFrameIB(const char *name, int kind) : ::cPacket(name,kind)
{
    this->sLid_var = 0;
    this->dLid_var = 0;
    this->Pkey_var = 0;
    this->sl_var = 0;
    this->vl_var = 0;
    this->FrameType_var = 0;
}

IPoIBFrameIB::IPoIBFrameIB(const IPoIBFrameIB& other) : ::cPacket(other)
{
    copy(other);
}

IPoIBFrameIB::~IPoIBFrameIB()
{
}

IPoIBFrameIB& IPoIBFrameIB::operator=(const IPoIBFrameIB& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IPoIBFrameIB::copy(const IPoIBFrameIB& other)
{
    this->sLid_var = other.sLid_var;
    this->dLid_var = other.dLid_var;
    this->Pkey_var = other.Pkey_var;
    this->sl_var = other.sl_var;
    this->vl_var = other.vl_var;
    this->FrameType_var = other.FrameType_var;
}

void IPoIBFrameIB::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->sLid_var);
    doPacking(b,this->dLid_var);
    doPacking(b,this->Pkey_var);
    doPacking(b,this->sl_var);
    doPacking(b,this->vl_var);
    doPacking(b,this->FrameType_var);
}

void IPoIBFrameIB::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->sLid_var);
    doUnpacking(b,this->dLid_var);
    doUnpacking(b,this->Pkey_var);
    doUnpacking(b,this->sl_var);
    doUnpacking(b,this->vl_var);
    doUnpacking(b,this->FrameType_var);
}

int IPoIBFrameIB::getSLid() const
{
    return sLid_var;
}

void IPoIBFrameIB::setSLid(int sLid)
{
    this->sLid_var = sLid;
}

int IPoIBFrameIB::getDLid() const
{
    return dLid_var;
}

void IPoIBFrameIB::setDLid(int dLid)
{
    this->dLid_var = dLid;
}

int IPoIBFrameIB::getPkey() const
{
    return Pkey_var;
}

void IPoIBFrameIB::setPkey(int Pkey)
{
    this->Pkey_var = Pkey;
}

int IPoIBFrameIB::getSl() const
{
    return sl_var;
}

void IPoIBFrameIB::setSl(int sl)
{
    this->sl_var = sl;
}

int IPoIBFrameIB::getVl() const
{
    return vl_var;
}

void IPoIBFrameIB::setVl(int vl)
{
    this->vl_var = vl;
}

int IPoIBFrameIB::getFrameType() const
{
    return FrameType_var;
}

void IPoIBFrameIB::setFrameType(int FrameType)
{
    this->FrameType_var = FrameType;
}

class IPoIBFrameIBDescriptor : public cClassDescriptor
{
  public:
    IPoIBFrameIBDescriptor();
    virtual ~IPoIBFrameIBDescriptor();

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

Register_ClassDescriptor(IPoIBFrameIBDescriptor);

IPoIBFrameIBDescriptor::IPoIBFrameIBDescriptor() : cClassDescriptor("IPoIBFrameIB", "cPacket")
{
}

IPoIBFrameIBDescriptor::~IPoIBFrameIBDescriptor()
{
}

bool IPoIBFrameIBDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IPoIBFrameIB *>(obj)!=NULL;
}

const char *IPoIBFrameIBDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IPoIBFrameIBDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int IPoIBFrameIBDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *IPoIBFrameIBDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sLid",
        "dLid",
        "Pkey",
        "sl",
        "vl",
        "FrameType",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int IPoIBFrameIBDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sLid")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dLid")==0) return base+1;
    if (fieldName[0]=='P' && strcmp(fieldName, "Pkey")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sl")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "vl")==0) return base+4;
    if (fieldName[0]=='F' && strcmp(fieldName, "FrameType")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IPoIBFrameIBDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *IPoIBFrameIBDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int IPoIBFrameIBDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IPoIBFrameIB *pp = (IPoIBFrameIB *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IPoIBFrameIBDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IPoIBFrameIB *pp = (IPoIBFrameIB *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSLid());
        case 1: return long2string(pp->getDLid());
        case 2: return long2string(pp->getPkey());
        case 3: return long2string(pp->getSl());
        case 4: return long2string(pp->getVl());
        case 5: return long2string(pp->getFrameType());
        default: return "";
    }
}

bool IPoIBFrameIBDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IPoIBFrameIB *pp = (IPoIBFrameIB *)object; (void)pp;
    switch (field) {
        case 0: pp->setSLid(string2long(value)); return true;
        case 1: pp->setDLid(string2long(value)); return true;
        case 2: pp->setPkey(string2long(value)); return true;
        case 3: pp->setSl(string2long(value)); return true;
        case 4: pp->setVl(string2long(value)); return true;
        case 5: pp->setFrameType(string2long(value)); return true;
        default: return false;
    }
}

const char *IPoIBFrameIBDescriptor::getFieldStructName(void *object, int field) const
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

void *IPoIBFrameIBDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IPoIBFrameIB *pp = (IPoIBFrameIB *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


