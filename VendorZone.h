#ifndef VENDORZONE_H
#define VENDORZONE_H

#include "EventGroup.h"
#include <string>
/**
 * @file VendorZone.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */
class VendorZone : public EventGroup
{
public:
    /**
     * @brief Constructor
     * @param name the title of the MainHall
     * @param t_capacity the max size of the MainHall
     */
    VendorZone(std::string name, int t_capacity);

    /**
     * @brief Implementation of the Composite Print
     */
    void print();
};

#endif