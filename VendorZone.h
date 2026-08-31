#ifndef VENDORZONE_H
#define VENDORZONE_H

#include "EventGroup.h"
#include <string>

class VendorZone : public EventGroup
{
public:
    VendorZone(std::string name);
    void print();
};

#endif