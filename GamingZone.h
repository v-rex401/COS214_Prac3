#ifndef GAMINGZONE_H
#define GAMINGZONE_H

#include "EventGroup.h"
#include <string>

class GamingZone : public EventGroup
{
public:
    GamingZone(std::string name);
    void print();
};

#endif