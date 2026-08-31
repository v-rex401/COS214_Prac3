#include "SecurityGuard.h"
#include <iostream>

SecurityGuard::SecurityGuard(std::string name) : EventUnit(name) {
}

void SecurityGuard::print() {
    
    switch (this->getCurrentNotice().getType()) {
        case NoticeType::BEGIN:
            std::cout << "[SECURITY] " << this->getName() << " is taking their post and securing the perimeter for opening." << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[SECURITY] " << this->getName() << " is escorting remaining attendees out and locking down." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[SECURITY] " << this->getName() << " is managing the crowd queue and maintaining order during the delay." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[SECURITY] " << this->getName() << " is halting entry at the doors; maximum capacity reached!" << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[SECURITY] " << this->getName() << " is loudly directing attendees to the nearest emergency exits!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[SECURITY] " << this->getName() << " is suppressing panic and clearing paths for emergency fire services!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[SECURITY] " << this->getName() << " is holding the line and securing loose outdoor structures." << std::endl;
            break;
            
        default:
            std::cout << "[SECURITY] " << this->getName() << " acknowledges notice: " << this->getCurrentNotice().getMsg() << std::endl;
            break;
    }
}