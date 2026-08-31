#include "CosplayStage.h"
#include <iostream>

CosplayStage::CosplayStage(std::string name) : EventUnit(name) {
}

void CosplayStage::print() {
    
    switch (this->getCurrentNotice().getType()) {
        case NoticeType::BEGIN:
            std::cout << "[COSPLAY] " << this->getName() << " is cueing the lights and welcoming the first cosplayers to the stage!" << std::endl;
            break;
            
        case NoticeType::END:
            std::cout << "[COSPLAY] " << this->getName() << " is concluding the final awards ceremony and powering down stage equipment." << std::endl;
            break;
            
        case NoticeType::DELAYED:
            std::cout << "[COSPLAY] " << this->getName() << " is pausing the showcase and asking performers to stand by backstage." << std::endl;
            break;
            
        case NoticeType::CAPACITY_ALERT:
            std::cout << "[COSPLAY] " << this->getName() << " is asking the audience to step back and clear the aisles for safety." << std::endl;
            break;
            
        case NoticeType::EVACUATE:
            std::cout << "[COSPLAY] " << this->getName() << " is cutting the music and directing the audience to the nearest emergency exits!" << std::endl;
            break;
            
        case NoticeType::FIRE:
            std::cout << "[COSPLAY] " << this->getName() << " is dropping the fire curtain and clearing all performers from the stage!" << std::endl;
            break;
            
        case NoticeType::WEATHER_ALERT:
            std::cout << "[COSPLAY] " << this->getName() << " is securing stage props and moving scheduled outdoor photo shoots inside." << std::endl;
            break;
            
        default:
            std::cout << "[COSPLAY] " << this->getName() << " stage crew acknowledges notice: " << this->getCurrentNotice().getMsg() << std::endl;
            break;
    }
}