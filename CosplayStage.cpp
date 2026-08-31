#include "CosplayStage.h"
#include <iostream>

CosplayStage::CosplayStage(std::string name) : EventUnit(name) {
}

void CosplayStage::print() {
    
    switch (this->currentNotice.getType()) {
        case NoticeType::BEGIN:
            std::cout << "[COSPLAY] " << name << " is cueing the lights and welcoming the first cosplayers to the stage!" << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[COSPLAY] " << name << " is concluding the final awards ceremony and powering down stage equipment." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[COSPLAY] " << name << " is pausing the showcase and asking performers to stand by backstage." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[COSPLAY] " << name << " is asking the audience to step back and clear the aisles for safety." << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[COSPLAY] " << name << " is cutting the music and directing the audience to the nearest emergency exits!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[COSPLAY] " << name << " is dropping the fire curtain and clearing all performers from the stage!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[COSPLAY] " << name << " is securing stage props and moving scheduled outdoor photo shoots inside." << std::endl;
            break;
            
        default:
            std::cout << "[COSPLAY] " << name << " stage crew acknowledges notice: " << currentNotice.getMsg() << std::endl;
            break;
    }
}