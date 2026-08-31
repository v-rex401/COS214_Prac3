

#include "MainHall.h"
#include "EventNotice.h"
#include <iostream>

MainHall::MainHall(std::string name, int t_capacity) : EventGroup(name, t_capacity)
{
}
void MainHall::print()
{

    EventNotice noti = EventGroup::getNotice();
    enum NoticeType type = noti.getType();
    std::string message = noti.getMsg();

    std::cout << message << std::endl;
    switch (type)
    {
    case NoticeType::BEGIN:
        std::cout << "Main Hall Is open now" << std::endl;
        break;
    case NoticeType::END:
        std::cout << "Main Hall is closed now" << std::endl;
        break;
    case NoticeType::DELAYED:
        std::cout << "Main Hall opening is delayed, please wait outside" << std::endl;
        break;
    case NoticeType::CAPACITY_ALERT:

        std::cout << "Main Hall is too full - proceed to another hall" << std::endl;
        break;
    case NoticeType::EVACUATE:
        std::cout << "Please Evacuate Main Hall" << std::endl;
        break;
    case NoticeType::FIRE:
        std::cout << "Fire - please move outside" << std::endl;
        break;
    case NoticeType::WEATHER_ALERT:
        std::cout << "Please stay inside the Main Hall" << std::endl;
        break;
    }
}