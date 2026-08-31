#include "EventControl.h"
#include "EventNotice.h"
#include "EventSubject.h"
#include <iostream>

/**
 * @file EventControl.cpp
 * @brief EventControl is one of the concrete subjects
 * @class EventControl
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
    this->name = "Event Controller";
}
/**
 * @brief parameterized Constructor
 * @param name is the eventControl centres title
 */
EventControl::EventControl(std::string name, int total_cap)
{
    this->name = name;
    this->total_cap = total_cap;
    this->current_cap = 0;
}

/**
 * @brief Attach components to the componentList
 * @param cmp the component to add to the list
 */
void EventControl::add(EventComponent *cmp)
{
    if (current_cap + cmp->getCapacity() >= total_cap)
    {
        std::cout << "Violates capacity check\n";
        currentNotice = EventNotice(NoticeType::CAPACITY_ALERT, "Comic Con is reaching maximum capacity.");
        EventObserver* obs = dynamic_cast<EventObserver*>(cmp);
        if (obs != nullptr) {
            this->detach(obs); 
        }
    }
    else
    {
        current_cap += cmp->getCapacity();
        componentList.push_back(cmp); /**insert at back of vector */
    }
}

/**
 * @brief remove the component from EventControl
 * Event Control is a composite participant
 * EventGroups are removed with this function by
 * searching through the list of components associated with EventControl
 */
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

/**
 * @brief
 */

void EventControl::print()
{
    std::cout << "Comic Con is On" << std::endl;

    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] != nullptr)
        {
            componentList[i]->print();
        }
    }
}

int EventControl::getCapacity()
{
    return current_cap;
}