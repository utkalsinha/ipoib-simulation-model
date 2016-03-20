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

#ifndef ETHERNETHARDWAREADDRESSFIELDS_H_
#define ETHERNETHARDWAREADDRESSFIELDS_H_

#include <MACAddress.h>

class EthernetHardwareAddressFields {
    inet::MACAddress MacAddress;
    int VID;
public:
    EthernetHardwareAddressFields();
    virtual ~EthernetHardwareAddressFields();
    EthernetHardwareAddressFields(inet::MACAddress macAddr,int vid);
    virtual inet::MACAddress getmacAddr();
    virtual void setmacAddr(inet::MACAddress macAddr);
    virtual int getVid();
    virtual void setVid(int vid);
};

#endif /* ETHERNETHARDWAREADDRESSFIELDS_H_ */
