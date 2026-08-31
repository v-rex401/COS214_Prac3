#include "Vendor.h"
#include <iostream>

Vendor::Vendor(std::string name, int capacity) : EventUnit(name, capacity) {
}

void Vendor::print() {

    switch (this->getCurrentNotice().getType()) {
        case NoticeType::BEGIN:
            std::cout << "[VENDOR] " << this->getName() << " is opening the stall, unboxing stock, and firing up the grills for the first customers!" << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[VENDOR] " << this->getName() << " is closing out the registers, packing up unsold merchandise, and cleaning the stall area." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[VENDOR] " << this->getName() << " is pausing sales and asking the customer line to remain orderly." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[VENDOR] " << this->getName() << " is experiencing maximum customer traffic and calling in backup staff!" << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[VENDOR] " << this->getName() << " is dropping everything, leaving the stall behind, and heading to the exits!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[VENDOR] " << this->getName() << " is immediately shutting off all cooking gas valves and clearing the area!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[VENDOR] " << this->getName() << " is lowering the tent awning and securing loose stock from the elements." << std::endl;
            break;
            
        default:
            std::cout << "[VENDOR] " << this->getName() << " staff acknowledges notice: " << getCurrentNotice().getMsg() << std::endl;
            break;
    }
}