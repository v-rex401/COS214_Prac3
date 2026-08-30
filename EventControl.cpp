#include "EventControl.h"
#include "EventNotice.h"
/**
 * @file EventControl.cpp
 * @brief EventControl is the concrete subject
 * @author Vashti
 */

EventNotice EventControl::getNotice()
{
    return currentNotice;
}
/**
 * @brief Default Constructor
 */
EventControl::EventControl()
{
    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] != nullptr)
        {
            delete componentList[i];
        }
    }
}
/**
 * @brief parameterized Constructor
 */
EventControl::EventControl(std::string name)
{
    this->name = name;
}

/**
 * @brief add function to attach components
 */
void EventControl::add(EventComponent *cmp)
{
    componentList.push_back(cmp);
}

void EventControl::remove(EventComponent *cmp)
{
    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] == cmp)
        {
            componentList.erase(componentList.begin() + i);
        }
    }
}