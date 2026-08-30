#include "EventControl.h"
#include "EventNotice.h"
#include "EventSubject.h"
/**
 * @file EventControl.cpp
 * @brief EventControl is the concrete subject
 * @author Vashti
 */

/**
 * @brief Return the current notice to be issued
 * @return currentNotice
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
}
/**
 * @brief parameterized Constructor
 * @param name the name of the eventControl centre
 */
EventControl::EventControl(std::string name)
{
    this->name = name;
}

/**
 * @brief add function to attach components to the componentList
 * @param cmp The component to add
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

/**
 * @brief Send the alert to observers, since we are using pull method, obersvers must get current state
 */
void EventControl::alert(EventNotice noti)
{
    currentNotice = noti;   //**Set the new notice  */
    EventSubject::notify(); /**Update the observers  */
}

/**
 * @brief Destructor
 */
EventControl::~EventControl()
{
    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] != nullptr)
        {
            delete componentList[i];
        }
    }
}