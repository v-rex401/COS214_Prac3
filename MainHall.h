#ifndef MAINHALL_H
#define MAINHALL_H

#include "EventGroup.h"
#include <string>

/**
 * @file MainHall.h
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */
class MainHall : public EventGroup
{
public:
    /**
     * @brief  DefaultConstructor
     * @param name the title of the MainHall
     * @param t_capacity the max size of the MainHall
     */
    MainHall(std::string name, int t_capacity);

    /**
     * @brief Implementation of the Composite Print
     */
    void print();
};

#endif