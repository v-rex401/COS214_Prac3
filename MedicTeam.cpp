#include "MedicTeam.h"
#include <iostream>

MedicTeam::MedicTeam(std::string name, int capacity) : EventUnit(name,capacity) {
}

void MedicTeam::print() {
    
    switch (this->getCurrentNotice().getType()) {
        case NoticeType::BEGIN:
            std::cout << "[MEDIC] " << this->getName() << " is setting up the first aid station and unpacking medical supplies." << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[MEDIC] " << this->getName() << " is packing up medical equipment and submitting incident reports." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[MEDIC] " << this->getName() << " is on standby, monitoring the queue for dehydration or fatigue." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[MEDIC] " << this->getName() << " is preparing for potential heat exhaustion and crowd crush injuries." << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[MEDIC] " << this->getName() << " is assisting mobility-impaired attendees with the evacuation route!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[MEDIC] " << this->getName() << " is setting up an emergency triage zone a safe distance from the fire!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[MEDIC] " << this->getName() << " is securing mobile stretchers and moving outdoor medical supplies inside." << std::endl;
            break;
            
        default:
            std::cout << "[MEDIC] " << this->getName() << " acknowledges medical notice: " << this->getCurrentNotice().getMsg() << std::endl;
            break;
    }
}