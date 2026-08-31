

#include "GamingZone.h"
#include <iostream>

GamingZone::GamingZone(std::string name, int t_capacity) : EventGroup(name, t_capacity)
{
}
void GamingZone::print()
{

    EventNotice noti = EventGroup::getNotice();
    enum NoticeType type = noti.getType();
    std::string message = noti.getMsg();

    std::cout << message << std::endl;
    switch (type)
    {
    case NoticeType::BEGIN:
        std::cout << "Gaming Zone Is open now" << std::endl;
        break;
    case NoticeType::END:
        std::cout << "Gaming Zone is closed now" << std::endl;
        break;
    case NoticeType::DELAYED:
        std::cout << "Gaming Zone opening is delayed, please try another zone" << std::endl;
        break;
    case NoticeType::CAPACITY_ALERT:
        std::cout << "Gaming Zone is too full - proceed to another zone" << std::endl;
        break;
    case NoticeType::EVACUATE:
        std::cout << "Please Evacuate Gaming Zone" << std::endl;
        break;
    case NoticeType::FIRE:
        std::cout << "Fire - please move outside" << std::endl;
        break;
    case NoticeType::WEATHER_ALERT:
        std::cout << "Please stay inside or move to Main Hall" << std::endl;
        break;
    }
}