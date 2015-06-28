//
// Generated file, do not edit! Created by opp_msgc 4.5 from configureMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "configureMessage_m.h"

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

Register_Class(ConfigureMessage);

ConfigureMessage::ConfigureMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->source_var = 0;
    this->dest_var = 0;
    this->weights_var = 0;
    this->maxGeneratedPackets_var = 0;
}

ConfigureMessage::ConfigureMessage(const ConfigureMessage& other) : ::cMessage(other)
{
    copy(other);
}

ConfigureMessage::~ConfigureMessage()
{
}

ConfigureMessage& ConfigureMessage::operator=(const ConfigureMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ConfigureMessage::copy(const ConfigureMessage& other)
{
    this->source_var = other.source_var;
    this->dest_var = other.dest_var;
    this->weights_var = other.weights_var;
    this->maxGeneratedPackets_var = other.maxGeneratedPackets_var;
}

void ConfigureMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->dest_var);
    doPacking(b,this->weights_var);
    doPacking(b,this->maxGeneratedPackets_var);
}

void ConfigureMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->weights_var);
    doUnpacking(b,this->maxGeneratedPackets_var);
}

int ConfigureMessage::getSource() const
{
    return source_var;
}

void ConfigureMessage::setSource(int source)
{
    this->source_var = source;
}

int ConfigureMessage::getDest() const
{
    return dest_var;
}

void ConfigureMessage::setDest(int dest)
{
    this->dest_var = dest;
}

const char * ConfigureMessage::getWeights() const
{
    return weights_var.c_str();
}

void ConfigureMessage::setWeights(const char * weights)
{
    this->weights_var = weights;
}

int ConfigureMessage::getMaxGeneratedPackets() const
{
    return maxGeneratedPackets_var;
}

void ConfigureMessage::setMaxGeneratedPackets(int maxGeneratedPackets)
{
    this->maxGeneratedPackets_var = maxGeneratedPackets;
}

class ConfigureMessageDescriptor : public cClassDescriptor
{
  public:
    ConfigureMessageDescriptor();
    virtual ~ConfigureMessageDescriptor();

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

Register_ClassDescriptor(ConfigureMessageDescriptor);

ConfigureMessageDescriptor::ConfigureMessageDescriptor() : cClassDescriptor("ConfigureMessage", "cMessage")
{
}

ConfigureMessageDescriptor::~ConfigureMessageDescriptor()
{
}

bool ConfigureMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ConfigureMessage *>(obj)!=NULL;
}

const char *ConfigureMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ConfigureMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int ConfigureMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *ConfigureMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "dest",
        "weights",
        "maxGeneratedPackets",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int ConfigureMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+1;
    if (fieldName[0]=='w' && strcmp(fieldName, "weights")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxGeneratedPackets")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ConfigureMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "string",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *ConfigureMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ConfigureMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ConfigureMessage *pp = (ConfigureMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ConfigureMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ConfigureMessage *pp = (ConfigureMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return long2string(pp->getDest());
        case 2: return oppstring2string(pp->getWeights());
        case 3: return long2string(pp->getMaxGeneratedPackets());
        default: return "";
    }
}

bool ConfigureMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ConfigureMessage *pp = (ConfigureMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setDest(string2long(value)); return true;
        case 2: pp->setWeights((value)); return true;
        case 3: pp->setMaxGeneratedPackets(string2long(value)); return true;
        default: return false;
    }
}

const char *ConfigureMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *ConfigureMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ConfigureMessage *pp = (ConfigureMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


