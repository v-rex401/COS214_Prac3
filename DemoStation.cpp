#include "DemoStation.h"
#include <iostream>

DemoStation::DemoStation(std::string name) : EventUnit(name) {
}

void DemoStation::print() {

    switch (this->getCurrentNotice().getType()) {
        case NoticeType::BEGIN:
            std::cout << "[DEMO] " << this->getName() << " is booting up the PCs and consoles, and loading the latest game demos!" << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[DEMO] " << this->getName() << " is wiping down controllers, logging out of accounts, and powering down systems." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[DEMO] " << this->getName() << " is pausing all active multiplayer sessions and asking players to hold." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[DEMO] " << this->getName() << " is enforcing strict 10-minute demo limits to keep the line moving." << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[DEMO] " << this->getName() << " is instructing players to drop their controllers and head to the exits immediately!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[DEMO] " << this->getName() << " is hitting the main hardware power kill switch and clearing the booth!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[DEMO] " << this->getName() << " is covering monitors and electronics to protect them from potential leaks." << std::endl;
            break;
            
        default:
            std::cout << "[DEMO] " << this->getName() << " booth staff acknowledges notice: " << this->getCurrentNotice().getMsg() << std::endl;
            break;
    }
}