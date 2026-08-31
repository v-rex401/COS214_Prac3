#ifndef MAINHALL_H
#define MAINHALL_H

#include "EventGroup.h"
#include <string>

class MainHall : public EventGroup
{
public:
    MainHall(std::string name, int t_capacity);
    void print();
};

#endif