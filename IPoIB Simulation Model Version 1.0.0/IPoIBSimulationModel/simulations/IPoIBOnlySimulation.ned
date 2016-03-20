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

package totfgatewayvthree.simulations;

import totfgatewayvthree.GlobalListenerModule;
import totfgatewayvthree.HCANode;
import totfgatewayvthree.IbSwitch;


network IPoIBOnlySimulation
{
    @networkNode;
    @display("bgb=760,520");
    types:
        channel IBFDR4X extends ned.DatarateChannel
        {
            // FDR per lane speed is 14.0625. Most IB HCA ports have 4 lanes or 4X links. So total link speed = 14 * 4 = 56Gbps
            datarate = 54Gbps;
            //delay = 1.4ns;
        }



    submodules:
        hcaNode: HCANode {
            @display("p=120,166");
        }
        hcaNode1: HCANode {
            @display("p=400,82");
        }
        hcaNode2: HCANode {
            @display("p=646,151");
        }
        hcaNode3: HCANode {
            @display("p=544,389");
        }
        hcaNode4: HCANode {
            @display("p=247,400");
        }
        ibSwitch: IbSwitch {
            @display("p=391,264");
        }
        globalListenerModule: GlobalListenerModule {
            @display("p=193,50");
        }

    connections:
        hcaNode1.hcaNetport <--> IBFDR4X <--> ibSwitch.connectedToPort1;
        hcaNode2.hcaNetport <--> IBFDR4X <--> ibSwitch.connectedToPort2;
        hcaNode3.hcaNetport <--> IBFDR4X <--> ibSwitch.connectedToPort3;
        hcaNode4.hcaNetport <--> IBFDR4X <--> ibSwitch.connectedToPort4;
        hcaNode.hcaNetport <--> IBFDR4X <--> ibSwitch.connectedToPort5;
}
