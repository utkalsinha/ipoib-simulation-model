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

package totfgatewayvthree;

module IbSwitch
{
    @display("i=old/switch2;bgb=704,251");

    gates:
        inout connectedToPort1;
        inout connectedToPort2;
        inout connectedToPort3;
        inout connectedToPort4;
        inout connectedToPort5;
    submodules:
        ibSwitchLogic: IbSwitchLogic {
            @display("p=349,66");
        }
        hcaPort1: HCAPort {
            @display("p=66,170");
        }
        hcaPort2: HCAPort {
            @display("p=204,170");
        }
        hcaPort3: HCAPort {
            @display("p=349,170");
        }
        hcaPort4: HCAPort {
            @display("p=497,170");
        }
        hcaPort5: HCAPort {
            @display("p=640,170");
        }
    connections:
        hcaPort1.toUpperLayer --> ibSwitchLogic.fromPort1;
        ibSwitchLogic.toPort1 --> hcaPort1.fromUpperLayer;
        hcaPort2.toUpperLayer --> ibSwitchLogic.fromPort2;
        ibSwitchLogic.toPort2 --> hcaPort2.fromUpperLayer;
        hcaPort3.toUpperLayer --> ibSwitchLogic.fromPort3;
        ibSwitchLogic.toPort3 --> hcaPort3.fromUpperLayer;
        hcaPort4.toUpperLayer --> ibSwitchLogic.fromPort4;
        ibSwitchLogic.toPort4 --> hcaPort4.fromUpperLayer;
        hcaPort5.toUpperLayer --> ibSwitchLogic.fromPort5;
        ibSwitchLogic.toPort5 --> hcaPort5.fromUpperLayer;
        hcaPort1.netport <--> connectedToPort1;
        hcaPort2.netport <--> connectedToPort2;
        hcaPort3.netport <--> connectedToPort3;
        hcaPort4.netport <--> connectedToPort4;
        hcaPort5.netport <--> connectedToPort5;
}
