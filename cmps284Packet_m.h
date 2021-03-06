//
// Generated file, do not edit! Created by opp_msgc 4.5 from cmps284Packet.msg.
//

#ifndef _CMPS284PACKET_M_H_
#define _CMPS284PACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>cmps284Packet.msg</tt> by opp_msgc.
 * <pre>
 * message cmps284Packet
 * {
 * 	int pathWeight;
 *     int packetSize;
 *     simtime_t pcktTimeStamp;
 * 	int srcID;
 * 	int destID;
 * }
 * </pre>
 */
class cmps284Packet : public ::cMessage
{
  protected:
    int pathWeight_var;
    int packetSize_var;
    simtime_t pcktTimeStamp_var;
    int srcID_var;
    int destID_var;

  private:
    void copy(const cmps284Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const cmps284Packet&);

  public:
    cmps284Packet(const char *name=NULL, int kind=0);
    cmps284Packet(const cmps284Packet& other);
    virtual ~cmps284Packet();
    cmps284Packet& operator=(const cmps284Packet& other);
    virtual cmps284Packet *dup() const {return new cmps284Packet(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getPathWeight() const;
    virtual void setPathWeight(int pathWeight);
    virtual int getPacketSize() const;
    virtual void setPacketSize(int packetSize);
    virtual simtime_t getPcktTimeStamp() const;
    virtual void setPcktTimeStamp(simtime_t pcktTimeStamp);
    virtual int getSrcID() const;
    virtual void setSrcID(int srcID);
    virtual int getDestID() const;
    virtual void setDestID(int destID);
};

inline void doPacking(cCommBuffer *b, cmps284Packet& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, cmps284Packet& obj) {obj.parsimUnpack(b);}


#endif // _CMPS284PACKET_M_H_
