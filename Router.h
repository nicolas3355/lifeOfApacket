//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef ROUTER_H_
#define ROUTER_H_
#include <iostream>
#include <fstream>

#include <omnetpp.h>
#include "configureMessage_m.h"
#include "cmps284Packet_m.h"
#include "trafficGen.h"
#include <vector>
#include <string.h>
using namespace std;
class Router : public cSimpleModule
{
private:
    int address;
    int destination;
    int source;
    string weightsStr="";
    int countPackets=0;
    int maxGeneratedPackets;

    typedef map<int,int> RoutingTable;
    RoutingTable rtable;
    //map forwarding table destaddress->nextNode
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void initializeRoutingTable(vector<double >& weights);
    virtual void Tokenize(const string& str,
                          vector<double>& tokens,
                          const string& delimiters = " ");
    virtual void generateMessages();
    virtual void stopMessageGeneration();
    virtual int getShortestPathWeight(int source,int destination, vector<double>& weights);
    virtual void printToFile(string str);
};

#endif /* ROUTER_H_ */
