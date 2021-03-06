//
// Generated file, do not edit! Created by opp_msgc 4.5 from configureMessage.msg.
//

#ifndef _CONFIGUREMESSAGE_M_H_
#define _CONFIGUREMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>configureMessage.msg</tt> by opp_msgc.
 * <pre>
 * message ConfigureMessage {
 *     int source;
 *     int dest;
 *     string weights;
 *     int maxGeneratedPackets;
 * }
 * </pre>
 */
class ConfigureMessage : public ::cMessage
{
  protected:
    int source_var;
    int dest_var;
    opp_string weights_var;
    int maxGeneratedPackets_var;

  private:
    void copy(const ConfigureMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ConfigureMessage&);

  public:
    ConfigureMessage(const char *name=NULL, int kind=0);
    ConfigureMessage(const ConfigureMessage& other);
    virtual ~ConfigureMessage();
    ConfigureMessage& operator=(const ConfigureMessage& other);
    virtual ConfigureMessage *dup() const {return new ConfigureMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDest() const;
    virtual void setDest(int dest);
    virtual const char * getWeights() const;
    virtual void setWeights(const char * weights);
    virtual int getMaxGeneratedPackets() const;
    virtual void setMaxGeneratedPackets(int maxGeneratedPackets);
};

inline void doPacking(cCommBuffer *b, ConfigureMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ConfigureMessage& obj) {obj.parsimUnpack(b);}


#endif // _CONFIGUREMESSAGE_M_H_
