/**
 * @file MainHall.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */

#include "EventGroup.h"
#include "EventNotice.h"
#include <iostream>

/**
 * @brief Forward Declaration
 */
class MainHall : public EventGroup
{
public:
    void print();
};

/**
 * @brief  Implementation
 */
void MainHall::print()
{
    EventNotice noti = EventGroup::getNotice();
    enum NoticeType type = noti.getType(); /** @todo Implement getType in EventNotice Class */

    switch (type)
    {
    case 0:
        std::cout << "Main Hall Is open now" << std::endl;
        break;
    case 1:
        std::cout << "Main Hall is closed now" << std::endl;
        break;
    case 2:
        std::cout << "Main Hall has been delayed" << std::endl;
        break;
    case 3:
        std::cout << "Main Hall is too full - proceed to Gaming Hall" << std::endl;
        break;
    case 4:
        std::cout << "Please Evacuate Main Hall" << std::endl;
        break;
    case 5:
        std::cout << "Fire - please move outside" << std::endl;
        break;
    case 6:
        std::cout << "Please stay inside the Main Hall" << std::endl;
        break;
    }
}