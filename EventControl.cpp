#include "EventControl.h"
#include "EventNotice.h"
#include "EventSubject.h"
#include <iostream>

EventNotice EventControl::getNotice()
{
    return currentNotice;
}

EventControl::EventControl()
{
    this->name = "Event Controller";
}

EventControl::EventControl(std::string name, int total_cap)
{
    this->name = name;
    this->total_cap = total_cap;
    this->current_cap = 0;
}

void EventControl::add(EventComponent *cmp)
{
    if (current_cap + cmp->getCapacity() >= total_cap)
    {
        std::cout << this->name + " Violates capacity check\n";
        currentNotice = EventNotice(NoticeType::CAPACITY_ALERT, "Comic Con is reaching maximum capacity.");
        EventObserver *obs = dynamic_cast<EventObserver *>(cmp);
        if (obs != nullptr)
        {
            this->detach(obs);
        }
    }
    else
    {
        current_cap += cmp->getCapacity();
        componentList.push_back(cmp); /**insert at back of vector */
    }
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

void EventControl::alert(EventNotice noti)
{
    currentNotice = noti;   /**Set the new notice  */
    EventSubject::notify(); /**Update the observers  */
}

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