#include "EventControl.h"
#include "EventNotice.h"
#include "EventSubject.h"
/**
 * @file EventControl.cpp
 * @brief EventControl is one of the concrete subjects
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
 * @param name is the eventControl centres title
 */
EventControl::EventControl(std::string name)
{
    this->name = name;
}

/**
 * @brief Attach components to the componentList
 * @param cmp the component to add to the list
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
            componentList.erase(componentList.begin() + i); /** Shift all the elements to fill the gap  */
        }
    }
}

/**
 * @brief Send the alert to observers
 * We are using the Pull Method. The currentNotice will be stored
 * and all concrete observers will have to pull the update from Subject
 */
void EventControl::alert(EventNotice noti)
{
    currentNotice = noti;   /**Set the new notice  */
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