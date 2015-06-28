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

#include <NMU.h>

Define_Module(NMU)
void NMU::initialize(){
    //parse the source, dest, weights
    weights = par("weights").stringValue();
    source = par("source").longValue();
    dest = par("dest").longValue();
    maxGeneratedPackets = par("maxGeneratedPackets").longValue();


    //scheuale the first event
    scheduleAt(0, new cMessage());

}
void NMU::handleMessage(cMessage *msg){
    //send configuration message
    ConfigureMessage *sms = new ConfigureMessage();
    sms->setWeights(weights.c_str());
    sms->setSource(source);
    sms->setDest(dest);
    sms->setMaxGeneratedPackets(maxGeneratedPackets);

    send(sms,"out");

}
/*NMU::NMU() {
    // TODO Auto-generated constructor stub

}

NMU::~NMU() {
    // TODO Auto-generated destructor stub
}*/

