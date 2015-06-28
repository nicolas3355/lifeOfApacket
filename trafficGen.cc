/*
 * trafficGen.cc
 *
 *
 * Author: Ahmad R. Dhaini
 * CMPS 200 - Computer Networks
 * Fall 2014-15
 * American University of Beirut
 *
 */

#include "trafficGen.h"

Define_Module(trafficGen);

trafficGen::trafficGen()
{

}

trafficGen::~trafficGen()
{

}

/* Initialize Module */
void trafficGen::initialize(int stage)
{
	// set configuration paramters
    data_arrival_rate = par("traffic_data_rate");
	STOP = true;
	DATAPktSize = par("packet_size");

	interArrival_time = 0;

	/* Start trafficGen*/
	if(!STOP)
    	startGenerator();
}

/*
 * Handle Message and run proper trafficGen according to the traffic type
 */
void trafficGen::handleMessage(cMessage* msg)
{
	if (STOP)
		return;

   // Create and send packet based on type
    createAndSendPacket(getRandomPacketLength(),simTime());

    /*Schedule Next Packet based on exponential data arrival */
    scheduleAt(simTime() + exponential(interArrival_time), msg);
}

/* Finish Events */
void trafficGen::finish()
{
	
}

/*
 * Start trafficGen
 */
void trafficGen::startGenerator()
{
	/* This function call is required if calling a function of one module from another module */
	Enter_Method("trafficGen::startGenerator()");

	STOP = false;

	/* Calculate inter-arrival time */
	calcInterArrival(data_arrival_rate, DATAPktSize, DATAPktSize);

	if (interArrival_time == 0)
	{
		return;
	}
	// Schedule an event for sending the first packet.
	// Self Generated Msg
	SELF* self_msg = new SELF();
	self_msg->setKind(1); // 0: DATA, 1: Self message
    scheduleAt(simTime() + exponential(interArrival_time), self_msg);
}


/* Stop trafficGen */
void trafficGen::stopGenerator()
{
	/* This function call is required if calling a function of one module from another module */
	Enter_Method("trafficGen::stopGenerator()");

	STOP = true;
}

/* Calculate Inter-Arrival based on the transmission rate */
void trafficGen::calcInterArrival(long double data_rate, int minSize, int maxSize)
{
	/* Calculate interArrival_time */
	long double packetsPerSec = (long double)(data_rate / (double)(getMeanPacketLength(minSize,maxSize)*8.0));

	if (data_rate == 0)
	{
		interArrival_time = 0;
	}
	else
		interArrival_time = (long double)(1.0/packetsPerSec);
}


/* Get Random Packet Length */
int trafficGen::getRandomPacketLength()
{
	return ((int)intuniform(DATAPktSize,DATAPktSize));
}

/* Get Mean Packet Length */
int trafficGen::getMeanPacketLength(int minSize, int maxSize)
{
	return (minSize + maxSize)/2;
}

/* Create packet to be sent */
void trafficGen::createAndSendPacket(int length, simtime_t timeStamp)
{

	/* Create New Packet */
	cmps284Packet* packet = new cmps284Packet("DATA Packet");

	/* TODO 
	*
	* Must be updated according to the (s,d) pair of the NMU
	*/
	int destID = 0; // Get ID from NMU message
	int srcID = 0; //parent node ID

	packet->setSrcID(srcID);
	packet->setDestID(destID);
	packet->setPacketSize(length);	//dataLength field in packet (Bytes)
    packet->setTimestamp(timeStamp);
 	packet->setKind(0); //0 for DATA
	packet->setPathWeight(0);

   /* Send Packet to BufferQ */
    sendDelayed(packet,0,"to_out");
}