#include "EventGroup.h"

/**
 * @file EventGroup.cpp
 * @brief Concrete Subject and Concrete Observer Implementation
 * @class EventGroup
 * @author Vashti
 *
 */

/**
 * @brief Parameterized Constructor
 */
EventGroup::EventGroup(std::string name)
{
    this->name = name;
}

/**
 * @brief Pull update from the subject
 * This behaviour applies to ConcreteObserver
 */
void EventGroup::update()
{
    currentNotice = parent->getNotice();
}

/**
 * @brief This behaviour applied to ConcreteSubject
 * @return currentNotice
 */
EventNotice EventGroup::getNotice()
{
    return currentNotice;
}

/**
 * @brief This behaviour applied to ConcreteSubject
 */
void EventGroup::setParent(EventSubject *par)
{
    parent = par;
}

/**
 * @brief This behaviour applied to Composite Design Pattern
 */
void EventGroup::add(EventComponent *cmp)
{
    componentList.push_back(cmp);
}

/**
 * @brief This behaviour applied to Composite Design Pattern
 */
void EventGroup::remove(EventComponent *cmp)
{
    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] == cmp)
        {
            componentList.erase(componentList.begin() + i); /** Shift all the elements to fill the gap  */
        }
    }
}

/**
 * @brief EventGroup is responsible for its parent pointer
 * and also the componentList it keeps
 */
EventGroup::~EventGroup()
{
    delete parent;
    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] != nullptr)
        {
            delete componentList[i];
        }
    }
}