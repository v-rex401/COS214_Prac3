/**
 * @file GamingZone.cpp
 * @brief One of the ConcreteSubjects which is also a ConcreteObserver
 * @author Vashti
 */

#include "EventGroup.h"
#include <iostream>

/**
 * @brief Forward Declaration
 */
class GamingZone : public EventGroup
{
public:
    void print();
};

/**
 * @brief  Implementation
 */
void GamingZone::print()
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
        std::cout << "Gaming Zone Is open now" << std::endl;
        break;
    case 1:
        std::cout << "Gaming Zone is closed now" << std::endl;
        break;
    case 2:
        std::cout << "Gaming Zone opening is delayed, please try another zone" << std::endl;
        break;
    case 3:
        std::cout << "Gaming Zone is too full - proceed to another zone" << std::endl;
        break;
    case 4:
        std::cout << "Please Evacuate Gaming Zone" << std::endl;
        break;
    case 5:
        std::cout << "Fire - please move outside" << std::endl;
        break;
    case 6:
        std::cout << "Please stay inside or move to Main Hall" << std::endl;
        break;
    }

    /**
     * @brief Call all leaves and/or composites in Gaming Hall
     */

    std::vector<EventComponent *> list = getComponents();
    for (int i = 0; i < list.size(); i++)
    {
        list[i]->print();
    }
}