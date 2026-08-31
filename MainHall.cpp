/**
 * @file MainHall.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */

#include "EventGroup.h"
#include "EventNotice.h"
#include <iostream>

/**
 * @brief Forward Declaration used instead of header file
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
    /**
     * @brief Implementation of the Composite Print
     */
    EventNotice noti = EventGroup::getNotice();
    enum NoticeType type = noti.getType(); /** @todo Implement getType in EventNotice Class */
    std::string message = noti.getMsg();   /** @todo Implement getMsg in EventNotice Class */

    std::cout << message << std::endl;
    switch (type)
    {
    case 0:
        std::cout << "Main Hall Is open now" << std::endl;
        break;
    case 1:
        std::cout << "Main Hall is closed now" << std::endl;
        break;
    case 2:
        std::cout << "Main Hall opening is delayed, please wait outside" << std::endl;
        break;
    case 3:
        std::cout << "Main Hall is too full - proceed to another hall" << std::endl;
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

    /**
     * @brief Call all leaves and/or composites in Main Hall
     */

    std::vector<EventComponent *> list = getComponents();
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == nullptr)
        {
            list[i]->print();
        }
    }
}