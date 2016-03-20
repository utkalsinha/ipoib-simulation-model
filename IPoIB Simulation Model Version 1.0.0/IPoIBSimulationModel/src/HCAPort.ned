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
simple HCAPort
{
    parameters:
        @display("i=device/port");
        int vl0weight;
        int vl1weight;
        int vl2weight;
        int vl3weight;
        int vl4weight;
        int vl5weight;
        int vl6weight;
        int vl7weight;
        int vl8weight;
        int vl9weight;
        int vl10weight;
        int vl11weight;
        int vl12weight;
        int vl13weight;
        int vl14weight;
        int vl15weight; 
        
        int portLID; // this portLID has to be same as that of IPoIBLayer's LocalLId
        int portPkey; // this PKey has to be same as that of IPoIBLayer's Broadcast PKey
        
        double scheduleInterval @unit(us);
    gates:
        input fromUpperLayer;
        output toUpperLayer;
        inout netport;
}
