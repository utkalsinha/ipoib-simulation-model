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
simple IPoIBLayer
{
    parameters:
        @display("i=block/layer");
       // int IPBufSize = default(2048);
       int thisHcaPortLID;
       int thisHCAPortPkey;
       string SourceIP;
       int broadcastLID;
       int pKey;
       int QPBufSize; // 1024 Packets
       double scheduleInterval @unit(us);
    gates:
        //input fromIPAppGen;
        input fromIPAppGen1;
        input fromIPAppGen2;
        input fromIPAppGen3;
        input fromIPAppGen4;
        input fromIPAppGen5;
        input fromIPAppGen6;
        input fromIPAppGen7;
        input fromIPAppGen8;
        input fromIPAppGen9;
        input fromIPAppGen10;
        input fromIPAppGen11;
        input fromIPAppGen12;
        input fromIPAppGen13;
        input fromIPAppGen14;
        input fromIPAppGen15;
        input fromIPAppGen16;
        input fromBelowRecvQ;
        input fromBelowCompletionQ;
        output toBelowSendQ;
        output toIPoIBSink;
}
