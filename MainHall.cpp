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
class MainHall : public EventGroup
{
public:
    void print();
};

/**
 * @brief  Implementation
 */
void MainHall::print()
{
    std::cout << "Welcome to the Main Hall" << std::endl;
}