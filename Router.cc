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

#include "Router.h"

Define_Module(Router);

void Router::initialize() {


    //getting the if of each node
    address = getParentModule()->par("address").longValue();
    EV << "Initialize" << address<<endl;


}

void Router::handleMessage(cMessage *msg)
{
    //checking if we got a confiuration message
    ConfigureMessage *message = dynamic_cast<ConfigureMessage*>(msg);
    vector<double> weights;
    if (message !=0) {
        //we got a configuration message lets extract the info needed


        //checking to see if the message being received have the same weights if its than we have received this packet before
        //we can go ahead and assume that our neighbooring nodes have recived the conf message so lets send our message in case
        //we are the source
        if(weightsStr.compare(message->getWeights())==0){
            ev <<" already have these weights no need to anything";
            generateMessages();
            return;
        }
        //extract info from configuration
        EV <<"message being received has the following string: " <<message ->getWeights() <<endl;
        //put the weights in a vector to i can handle them better
        Tokenize(message->getWeights(),weights);
        //getting the configuration
        destination=message->getDest();
        ev << "destination address is :"<<destination <<endl;
        source=message->getSource();

        //setting the max number of packets allowed to being send in the generator
        maxGeneratedPackets=message->getMaxGeneratedPackets();

        ev << "maxGeneratedPackets :"<<maxGeneratedPackets <<endl;
        weightsStr=message->getWeights();


        //call dijesktra and fill the routing table
        initializeRoutingTable(weights);


        //loop over all the gates send a packet to everyone
        for (int i=0; i<gateSize("out"); i++) {
            ConfigureMessage *messageDup=message->dup();
            send(messageDup,"out",i);

        }

    }
    else {
        //it's not a configuration packet

        //get the weights again in the vectors for some reason they are being lost
        Tokenize(weightsStr,weights);

        //this must be a cmps packet
        cmps284Packet *message = dynamic_cast<cmps284Packet*>(msg);

        int oldDest=message->getSrcID();


        //check to see if we are already there
        if (destination == address){


                   //we received our first packet to the destination lets increment the count of packets being received

                    countPackets++;
                    if(countPackets>maxGeneratedPackets){
                        int weight=getShortestPathWeight(oldDest,address,weights);

                                //setting the new weight in the message
                                int newWeight=message->getPathWeight()+weight;
                                message->setPathWeight(newWeight);
                        //if countpackets is now bigger than max generatedpackets than we reached the end of this simulation

                        //lets print the total path it took and form a good paragraph to write to the file
                        string str="total path weight from source:" ;
                        str.append(to_string(source));
                        str.append(" to destination ");
                        str.append(to_string(destination));
                        str.append(" is:");

                        str.append(to_string(message-> getPathWeight()));
                        //printing the formed string
                        printToFile(str);
                        //stopping simulation
                        stopMessageGeneration();
                    }
                    //the packet has arrived lets continue no need to do anything
                    return;
                }

        //setting the proper destination and src for the message
        message->setDestID(destination);
        message->setSrcID(address);


        //searching in the table to see if the destination is avaialble
        RoutingTable::iterator it = rtable.find(destination);

        if (it == rtable.end()) {
            //if for some reason its not listed in our ttable we cant go any further
            ev << "Address " << destination << " unreachable, discarding packet " <<endl;
            delete message; message = NULL;
            return;
        }


        int outGateId = (*it).second;
        ev << simTime() << " Forwarding packet   on gate id = " << outGateId << endl;

        //getting the weight that it will take to go to the next node
        int weight=getShortestPathWeight(oldDest,address,weights);

        //setting the new weight in the message
        int newWeight=message->getPathWeight()+weight;
        message->setPathWeight(newWeight);

        //finally send the new message
        send(message, outGateId);





    }
}
void Router::initializeRoutingTable(vector<double>& weights){
    cTopology *topo = new cTopology("topo");

    //extract the topology.

    topo->extractByNedTypeName(cStringTokenizer ("Node").asVector());


    cTopology::Node *thisNode = topo->getNodeFor(getParentModule());

    //finding who we are in topo
    int indexOfThisNode;
    for(int i=0;i<topo->getNumNodes();i++){
        if(topo->getNode(i)==thisNode){
            indexOfThisNode=i;
        }
    }

    //set weights off all the nodes
    for(int i=0;i<topo->getNumNodes();i++){
        //since we stored everything 1d array and at each node we have different waits 14 each
        topo->getNode(i)->setWeight(weights.at(14*indexOfThisNode+i));
    }

    //find and store next hops
    for(int i=0;i<topo -> getNumNodes();i++){
        if(topo->getNode(i)==thisNode) continue; //skip this node , skip myself

        //find the shortest path

        topo ->calculateWeightedSingleShortestPathsTo(topo->getNode(i));

        if (thisNode->getNumPaths()==0) continue;//this node is not connected to any other node



        // thisNode->path(0) is the cTopology link from this node to
        // the next node along the lowest cost route which takes us to
        // the target node `topo->node(i)'.

        ev<<"hohohohoho:"<<thisNode->getPath(0)->getWeight();
        int gateId=thisNode->getPath(0)->getLocalGate()->getPreviousGate()->getId();


        // What was the address of the target node?
        int address = topo->getNode(i)->getModule()->par("address");

        // Update the routing table: address --> gateId
        rtable[address] = gateId;
        ev << "  towards address " << address << " gateId is " << gateId << endl;
    }
    ev << " " << endl;
    delete topo; topo = NULL;



}

void Router::Tokenize(const string& str,
        vector<double>& tokens,
        const string& delimiters)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(stod(str.substr(lastPos, pos - lastPos)));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}
void Router::generateMessages(){


    if (source==address){
        ev<<"hohoho"<<endl;

        cModule *trafficMod= getParentModule()->getSubmodule("trafficGen");

        trafficGen *traff= check_and_cast<trafficGen*>(trafficMod);

        traff->startGenerator();

    }
}
void Router::stopMessageGeneration(){
    cModule *trafficMod= getParentModule()->getSubmodule("trafficGen");

    trafficGen *traff= check_and_cast<trafficGen*>(trafficMod);


    traff->stopGenerator();
    //no matter what i do the stoop generator never seeem to work!!!!!!!
    endSimulation();

}
int Router::getShortestPathWeight(int source,int destination, vector<double>& weights){

           //since we stored everything 1d array and at each node we have different waits 14 each
            //we already know the shortest path based on our table going backwords to figure out the weight
           return (int)weights.at(14*source+destination);

}
void Router::printToFile(string str){

    ofstream myfile ("out.dat",ios::app);
    if(myfile.is_open()){

        myfile << str <<"\n";
        myfile.close();
    }
    else
        ev << "unable to open file";


}
