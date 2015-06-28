//
// Generated file, do not edit! Created by opp_msgc 4.5 from cmps284Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "cmps284Packet_m.h"

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

Register_Class(cmps284Packet);

cmps284Packet::cmps284Packet(const char *name, int kind) : ::cMessage(name,kind)
{
    this->pathWeight_var = 0;
    this->packetSize_var = 0;
    this->pcktTimeStamp_var = 0;
    this->srcID_var = 0;
    this->destID_var = 0;
}

cmps284Packet::cmps284Packet(const cmps284Packet& other) : ::cMessage(other)
{
    copy(other);
}

cmps284Packet::~cmps284Packet()
{
}

cmps284Packet& cmps284Packet::operator=(const cmps284Packet& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void cmps284Packet::copy(const cmps284Packet& other)
{
    this->pathWeight_var = other.pathWeight_var;
    this->packetSize_var = other.packetSize_var;
    this->pcktTimeStamp_var = other.pcktTimeStamp_var;
    this->srcID_var = other.srcID_var;
    this->destID_var = other.destID_var;
}

void cmps284Packet::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->pathWeight_var);
    doPacking(b,this->packetSize_var);
    doPacking(b,this->pcktTimeStamp_var);
    doPacking(b,this->srcID_var);
    doPacking(b,this->destID_var);
}

void cmps284Packet::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->pathWeight_var);
    doUnpacking(b,this->packetSize_var);
    doUnpacking(b,this->pcktTimeStamp_var);
    doUnpacking(b,this->srcID_var);
    doUnpacking(b,this->destID_var);
}

int cmps284Packet::getPathWeight() const
{
    return pathWeight_var;
}

void cmps284Packet::setPathWeight(int pathWeight)
{
    this->pathWeight_var = pathWeight;
}

int cmps284Packet::getPacketSize() const
{
    return packetSize_var;
}

void cmps284Packet::setPacketSize(int packetSize)
{
    this->packetSize_var = packetSize;
}

simtime_t cmps284Packet::getPcktTimeStamp() const
{
    return pcktTimeStamp_var;
}

void cmps284Packet::setPcktTimeStamp(simtime_t pcktTimeStamp)
{
    this->pcktTimeStamp_var = pcktTimeStamp;
}

int cmps284Packet::getSrcID() const
{
    return srcID_var;
}

void cmps284Packet::setSrcID(int srcID)
{
    this->srcID_var = srcID;
}

int cmps284Packet::getDestID() const
{
    return destID_var;
}

void cmps284Packet::setDestID(int destID)
{
    this->destID_var = destID;
}

class cmps284PacketDescriptor : public cClassDescriptor
{
  public:
    cmps284PacketDescriptor();
    virtual ~cmps284PacketDescriptor();

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

Register_ClassDescriptor(cmps284PacketDescriptor);

cmps284PacketDescriptor::cmps284PacketDescriptor() : cClassDescriptor("cmps284Packet", "cMessage")
{
}

cmps284PacketDescriptor::~cmps284PacketDescriptor()
{
}

bool cmps284PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<cmps284Packet *>(obj)!=NULL;
}

const char *cmps284PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int cmps284PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int cmps284PacketDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *cmps284PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pathWeight",
        "packetSize",
        "pcktTimeStamp",
        "srcID",
        "destID",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int cmps284PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathWeight")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetSize")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "pcktTimeStamp")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcID")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destID")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *cmps284PacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "simtime_t",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *cmps284PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int cmps284PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    cmps284Packet *pp = (cmps284Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string cmps284PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    cmps284Packet *pp = (cmps284Packet *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPathWeight());
        case 1: return long2string(pp->getPacketSize());
        case 2: return double2string(pp->getPcktTimeStamp());
        case 3: return long2string(pp->getSrcID());
        case 4: return long2string(pp->getDestID());
        default: return "";
    }
}

bool cmps284PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    cmps284Packet *pp = (cmps284Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setPathWeight(string2long(value)); return true;
        case 1: pp->setPacketSize(string2long(value)); return true;
        case 2: pp->setPcktTimeStamp(string2double(value)); return true;
        case 3: pp->setSrcID(string2long(value)); return true;
        case 4: pp->setDestID(string2long(value)); return true;
        default: return false;
    }
}

const char *cmps284PacketDescriptor::getFieldStructName(void *object, int field) const
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

void *cmps284PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    cmps284Packet *pp = (cmps284Packet *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


