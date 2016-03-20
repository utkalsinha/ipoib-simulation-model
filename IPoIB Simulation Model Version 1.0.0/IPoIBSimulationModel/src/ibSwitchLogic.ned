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

//
// TODO auto-generated module
//
simple IbSwitchLogic
{
    parameters:
        double switchingLatency @unit(ns)= default(0ns);
    @display("i=old/cogwheel2");
    gates:
        input fromPort1; 
        output toPort1; // naming convention is be "toPort" followed by the port number e.g., "toPort1", "toPort2";

        input fromPort2;
        output toPort2;

        input fromPort3;
        output toPort3;

        input fromPort4;
        output toPort4;

        input fromPort5;
        output toPort5;
}
