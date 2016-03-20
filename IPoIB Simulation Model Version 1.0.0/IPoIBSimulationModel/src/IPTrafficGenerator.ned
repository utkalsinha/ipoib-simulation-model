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
simple IPTrafficGenerator
{
    parameters:
        int numberOfBytesToCreateAndSend;// @unit(B) = default(1000*8B); // in bytes
        int mtuSize;// @unit(B) = default(1500B);
        string SourceIP;// = default("172.23.3.1");
        string DestinationIP;// = default("172.23.3.2");
        string netmask;// = default("255.255.0.0");
        int AppGenID;
        bool workingApp;
        
        double scheduleInterval @unit(us);
        @display("i=block/telnet");
        gates:
            output ToLowerLayer;
}
