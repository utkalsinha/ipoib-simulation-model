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

#include <cobjectfactory.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <EthernetPortFrameListener.h>
#include <GlobalListenerModule.h>
#include <regmacros.h>
#include <simutil.h>

Define_Module(GlobalListenerModule);

void GlobalListenerModule::initialize()
{
    // TODO - Generated method body
    frameListener = new EthernetPortFrameListener();
    simulation.getSystemModule()->subscribe("rxPk",frameListener);
}

void GlobalListenerModule::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void GlobalListenerModule::finish(){
    //unsubscribe("rxPk",frameListener);
    simulation.getSystemModule()->unsubscribe("rxPk",frameListener);
    recordScalar("Priority App 0 Total Latency", this->frameListener->LatencyPriority[0]);
    recordScalar("Priority App 1 Total Latency", this->frameListener->LatencyPriority[1]);
    recordScalar("Priority App 2 Total Latency", this->frameListener->LatencyPriority[2]);
    recordScalar("Priority App 3 Total Latency", this->frameListener->LatencyPriority[3]);
    recordScalar("Priority App 4 Total Latency", this->frameListener->LatencyPriority[4]);
    recordScalar("Priority App 5 Total Latency", this->frameListener->LatencyPriority[5]);
    recordScalar("Priority App 6 Total Latency", this->frameListener->LatencyPriority[6]);
    recordScalar("Priority App 7 Total Latency", this->frameListener->LatencyPriority[7]);
    recordScalar("Priority App 8 Total Latency", this->frameListener->LatencyPriority[8]);
    recordScalar("Priority App 9 Total Latency", this->frameListener->LatencyPriority[9]);
    recordScalar("Priority App 10 Total Latency", this->frameListener->LatencyPriority[10]);
    recordScalar("Priority App 11 Total Latency", this->frameListener->LatencyPriority[11]);
    recordScalar("Priority App 12 Total Latency", this->frameListener->LatencyPriority[12]);
    recordScalar("Priority App 13 Total Latency", this->frameListener->LatencyPriority[13]);
    recordScalar("Priority App 14 Total Latency", this->frameListener->LatencyPriority[14]);
    recordScalar("Priority App 15 Total Latency", this->frameListener->LatencyPriority[15]);
}
