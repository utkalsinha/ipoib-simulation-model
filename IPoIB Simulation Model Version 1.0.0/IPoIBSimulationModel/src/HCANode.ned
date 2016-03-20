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

module HCANode
{
    parameters:
        @display("i=device/server2;bgb=1077,571");
    gates:
        inout hcaNetport;
    submodules:
        hcaPort: HCAPort {
            @display("p=498,501");
        }
        queuePair: QueuePair {
                @display("p=498,427");
        }
        iPoIBLayer: IPoIBLayer {
            @display("p=498,348");
        }
        ipTrafficGenerator: IPTrafficGenerator {
            @display("p=44,234");
        }
        ipTrafficGenerator1: IPTrafficGenerator {
            @display("p=44,173");
        }
        ipTrafficGenerator2: IPTrafficGenerator {
            @display("p=44,112");
        }
        ipTrafficGenerator3: IPTrafficGenerator {
            @display("p=44,56");
        }
        ipTrafficGenerator4: IPTrafficGenerator {
            @display("p=164,56");
        }
        ipTrafficGenerator5: IPTrafficGenerator {
            @display("p=281,56");
        }
        ipTrafficGenerator6: IPTrafficGenerator {
            @display("p=393,56");
        }
        ipTrafficGenerator7: IPTrafficGenerator {
            @display("p=508,56");
        }
        ipTrafficGenerator8: IPTrafficGenerator {
            @display("p=618,56");
        }
        ipTrafficGenerator9: IPTrafficGenerator {
            @display("p=729,56");
        }
        ipTrafficGenerator10: IPTrafficGenerator {
            @display("p=846,56");
        }
        ipTrafficGenerator11: IPTrafficGenerator {
            @display("p=970,56");
        }
        ipTrafficGenerator12: IPTrafficGenerator {
            @display("p=966,120");
        }
        ipTrafficGenerator13: IPTrafficGenerator {
            @display("p=967,188");
        }
        ipTrafficGenerator14: IPTrafficGenerator {
            @display("p=966,267");
        }
        ipTrafficGenerator15: IPTrafficGenerator {
            @display("p=970,348");
        }
        iPoIBSink: IPoIBSink {
            @display("p=44,348");
        }


    connections:
        ipTrafficGenerator.ToLowerLayer --> iPoIBLayer.fromIPAppGen1;
        ipTrafficGenerator1.ToLowerLayer --> iPoIBLayer.fromIPAppGen2;
        ipTrafficGenerator2.ToLowerLayer --> iPoIBLayer.fromIPAppGen3;
        ipTrafficGenerator3.ToLowerLayer --> iPoIBLayer.fromIPAppGen4;
        ipTrafficGenerator4.ToLowerLayer --> iPoIBLayer.fromIPAppGen5;
        ipTrafficGenerator5.ToLowerLayer --> iPoIBLayer.fromIPAppGen6;
        ipTrafficGenerator6.ToLowerLayer --> iPoIBLayer.fromIPAppGen7;
        ipTrafficGenerator7.ToLowerLayer --> iPoIBLayer.fromIPAppGen8;
        ipTrafficGenerator8.ToLowerLayer --> iPoIBLayer.fromIPAppGen9;
        ipTrafficGenerator9.ToLowerLayer --> iPoIBLayer.fromIPAppGen10;
        ipTrafficGenerator10.ToLowerLayer --> iPoIBLayer.fromIPAppGen11;
        ipTrafficGenerator11.ToLowerLayer --> iPoIBLayer.fromIPAppGen12;
        ipTrafficGenerator12.ToLowerLayer --> iPoIBLayer.fromIPAppGen13;
        ipTrafficGenerator13.ToLowerLayer --> iPoIBLayer.fromIPAppGen14;
        ipTrafficGenerator14.ToLowerLayer --> iPoIBLayer.fromIPAppGen15;
        ipTrafficGenerator15.ToLowerLayer --> iPoIBLayer.fromIPAppGen16;
        iPoIBLayer.toIPoIBSink --> iPoIBSink.fromIPoIBLayer;
        iPoIBLayer.toBelowSendQ --> queuePair.fromIPoIBLayer;
        queuePair.fromBelowRecvQToIPoIBLayer --> iPoIBLayer.fromBelowRecvQ;
        queuePair.fromBelowCompletionQToIPoIBLayerStat --> iPoIBLayer.fromBelowCompletionQ;
        queuePair.toBelowHCAVL --> hcaPort.fromUpperLayer;
        hcaPort.toUpperLayer --> queuePair.fromBelowVLtoRecdQ;
        hcaPort.netport <--> hcaNetport;
}
