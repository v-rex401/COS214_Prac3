/**
 * @file GamingZone.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */

#include "EventGroup.h"
#include <iostream>

/**
 * @brief Forward Declaration
 */
class GamingZone : public EventGroup
{
public:
    void print();
};

/**
 * @brief  Implementation
 */
void GamingZone::print()
{
    std::cout << "Welcome to the GamingZone Hall" << std::endl;
}