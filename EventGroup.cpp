#include "EventGroup.h"
#include "iostream"

EventGroup::EventGroup(std::string name, int total_cap)
{
    this->name = name;
    this->total_cap = total_cap;
    this->current_cap = 0;
}

void EventGroup::update()
{
    currentNotice = parent->getNotice();
    this->print();
    this->notify();
}

EventNotice EventGroup::getNotice()
{
    return currentNotice;
}

void EventGroup::setParent(EventSubject *par)
{
    parent = par;
}

void EventGroup::add(EventComponent *cmp)
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
        componentList.push_back(cmp);
    }
}

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

EventGroup::~EventGroup()
{
    if (parent != nullptr)
    {
        parent->detach(this);
    }

    for (int i = 0; i < componentList.size(); i++)
    {
        if (componentList[i] != nullptr)
        {
            delete componentList[i];
        }
    }
}

std::vector<EventComponent *> EventGroup::getComponents()
{
    return componentList;
}

int EventGroup::getCapacity()
{
    return current_cap;
}
