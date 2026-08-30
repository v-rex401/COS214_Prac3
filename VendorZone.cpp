/**
 * @file MainHall.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */

#include "EventGroup.h"
#include <iostream>

/**
 * @brief Forward Declaration
 */
class VendorZone : public EventGroup
{
public:
    void print();
};

/**
 * @brief  Implementation
 */
void VendorZone::print()
{
    std::cout << "Welcome to the Main Hall" << std::endl;
}