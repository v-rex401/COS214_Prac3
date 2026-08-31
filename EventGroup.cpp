#include "EventGroup.h"
#include "iostream"
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
EventGroup::EventGroup(std::string name, int total_cap)
{
    this->name = name;
    this->total_cap = total_cap;
    this->current_cap = 0;
}

/**
 * @brief Pull update from the subject
 * This behaviour applies to ConcreteObserver
 */
void EventGroup::update()
{
    currentNotice = parent->getNotice();
    this->print();
    this->notify();
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
        componentList.push_back(cmp);
    }
    
    
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
    if (parent != nullptr) {
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

/**
 * @brief
 * @return componentList of type std::vector<EventComponent*>
 */

std::vector<EventComponent *> EventGroup::getComponents()
{
    return componentList;
}

int EventGroup::getCapacity()
{
    return current_cap;
}
