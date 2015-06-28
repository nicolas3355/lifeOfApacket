//
// Author: Ahmad R. Dhaini
// CMPS 284 - Computer Networks
// Fall 2014-15
// American University of Beirut
//
message cmps284Packet
{
	int pathWeight;
    int packetSize;
    simtime_t pcktTimeStamp;
	int srcID;
	int destID;
}