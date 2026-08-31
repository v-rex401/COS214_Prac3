/**
 * @file VendorZone.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */

#include "VendorZone.h"
#include <iostream>

/**
 * @brief  Constructor
 */
VendorZone::VendorZone(std::string name, int t_capacity) : EventGroup(name,t_capacity)
{
}
void VendorZone::print()
{
    /**
     * @brief Implementation of the Composite Print
     */
    EventNotice noti = EventGroup::getNotice();
    enum NoticeType type = noti.getType();
    std::string message = noti.getMsg();

    std::cout << message << std::endl;
    switch (type)
    {
    case NoticeType::BEGIN:
        std::cout << "Vendor Zone Is open now" << std::endl;
        break;
    case NoticeType::END:
        std::cout << "Vendor Zone is closed now" << std::endl;
        break;
    case NoticeType::DELAYED:
        std::cout << "Vendor Zone opening is delayed, please wait at the gate" << std::endl;
        break;
    case NoticeType::CAPACITY_ALERT:
        std::cout << "Vendor Zone is too full - proceed to another zone" << std::endl;
        break;
    case NoticeType::EVACUATE:
        std::cout << "Please Evacuate Vendor Zone" << std::endl;
        break;
    case NoticeType::FIRE:
        std::cout << "Fire - please move to evacuation point" << std::endl;
        break;
    case NoticeType::WEATHER_ALERT:
        std::cout << "Please stay inside the Vendor Zone" << std::endl;
        break;
    }

}