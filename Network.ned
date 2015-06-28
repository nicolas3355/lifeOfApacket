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
//
// TODO documentation
//
network Network
{
    @display("bgb=539,350");
    submodules:
        node: Node {
            address = 0;
            @display("p=106,130");
        }
        node1: Node {
            address =1;
            @display("p=60,195");
        }
        node2: Node {
            address=2;
            @display("p=85,263");
        }
        node3: Node {
            address=3;
            @display("p=135,195");
        }
        node4: Node {
            address=4;
            @display("p=201,208");
        }
        node5: Node {
            address=5;
            @display("p=162,279");
        }

        nmu: NMU {
            
            @display("p=46,91");
        }
        node6: Node {
            address=6;
            @display("p=263,195");
        }
        node7: Node {
            address=7;
            @display("p=318,295");
        }
        node8: Node {
            address=8;
            @display("p=326,183");
        }
        node9: Node {
            address=9;
            @display("p=387,169");
        }
        node10: Node {
            address=10;
            @display("p=387,85");
        }
        node11: Node {
            address=11;
            @display("p=464,46");
        }
        node12: Node {
            address=12;
            @display("p=436,234");
        }
        node13: Node {
            address=13;
            @display("p=514,110");
        }
    connections:


        nmu.out --> node.inNode++;

        node.outNode++ --> node1.inNode++;
        node.outNode++ --> node8.inNode++;
        node8.outNode++ --> node.inNode++;
        node1.outNode++ --> node.inNode++;
        node1.outNode++ --> node3.inNode++;
        node3.outNode++ --> node1.inNode++;
        node1.outNode++ --> node2.inNode++;
        node2.outNode++ --> node1.inNode++;
        node2.outNode++ --> node5.inNode++;
        node5.outNode++ --> node2.inNode++;
        node3.outNode++ --> node4.inNode++;
        node4.outNode++ --> node3.inNode++;
        node3.outNode++ --> node10.inNode++;
        node10.outNode++ --> node3.inNode++;
        node4.outNode++ --> node6.inNode++;
        node6.outNode++ --> node4.inNode++;
        node4.outNode++ --> node5.inNode++;
        node5.outNode++ --> node4.inNode++;
        node5.outNode++ --> node12.inNode++;
        node5.outNode++ --> node7.inNode++;
        node7.outNode++ --> node5.inNode++;
        node12.outNode++ --> node5.inNode++;
        node6.outNode++ --> node8.inNode++;
        node8.outNode++ --> node6.inNode++;
        node7.outNode++ --> node9.inNode++;
        node9.outNode++ --> node7.inNode++;
        node8.outNode++ --> node9.inNode++;
        node9.outNode++ --> node8.inNode++;
        node13.outNode++ --> node10.inNode++;
        node10.outNode++ --> node13.inNode++;
        node9.outNode++ --> node11.inNode++;
        node11.outNode++ --> node9.inNode++;
        node9.outNode++ --> node13.inNode++;
        node13.outNode++ --> node9.inNode++;
        node11.outNode++ --> node12.inNode++;
        node12.outNode++ --> node11.inNode++;
        node12.outNode++ --> node13.inNode++;
        node13.outNode++ --> node12.inNode++;
}

