#include "MedicTeam.h"
#include <iostream>

MedicTeam::MedicTeam(std::string name) : EventUnit(name) {
}

void MedicTeam::print() {
    
    switch (this->currentNotice.getType()) {
        case NoticeType::BEGIN:
            std::cout << "[MEDIC] " << name << " is setting up the first aid station and unpacking medical supplies." << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[MEDIC] " << name << " is packing up medical equipment and submitting incident reports." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[MEDIC] " << name << " is on standby, monitoring the queue for dehydration or fatigue." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[MEDIC] " << name << " is preparing for potential heat exhaustion and crowd crush injuries." << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[MEDIC] " << name << " is assisting mobility-impaired attendees with the evacuation route!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[MEDIC] " << name << " is setting up an emergency triage zone a safe distance from the fire!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[MEDIC] " << name << " is securing mobile stretchers and moving outdoor medical supplies inside." << std::endl;
            break;
            
        default:
            std::cout << "[MEDIC] " << name << " acknowledges medical notice: " << currentNotice.getMsg() << std::endl;
            break;
    }
}