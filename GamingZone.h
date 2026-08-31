#ifndef GAMINGZONE_H
#define GAMINGZONE_H

#include "EventGroup.h"
#include <string>
/**
 * @file GamingZone.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */
class GamingZone : public EventGroup
{
public:
    /**
     * @brief  Constructor
     * @param name the title of the MainHall
     * @param t_capacity the max size of the MainHall
     */
    GamingZone(std::string name, int t_capacity);

    /**
     * @brief Implementation of the Print for Composite Design Pattern
     */
    void print();

    /**
     * @deprecated Removed this implementation due to changes in structure
     * @code
     * std::vector<EventComponent *> list = getComponents();
     * for (int i = 0; i < list.size(); i++) {
     *   list[i]->print();
     *  }
     * @endcode
     */
};

#endif