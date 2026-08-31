#include "EventComponent.h"
#include "EventControl.h"
#include "EventNotice.h"
#include "EventGroup.h"
#include "MainHall.h"
#include "VendorZone.h"
#include "GamingZone.h"
#include "SecurityGuard.h"
#include "MedicTeam.h"
#include "CosplayStage.h"
#include "Vendor.h"
#include "DemoStation.h"
#include <iostream>

/**
 * @file main.cpp
 * @class main class
 * @brief The Client runs here
 */

int main()
{
    /** @todo Build and register event */

    /**Leaves */
    SecurityGuard *john = new SecurityGuard("John Doe");
    MedicTeam *mainMedics = new MedicTeam("Main Hall Medics");
    MedicTeam *vendorMedics = new MedicTeam("Vendor Zone Medics");
    CosplayStage *cosplayStage = new CosplayStage("Cosplay in Main Hall");
    Vendor *tacos = new Vendor("Taco Stand");
    Vendor *burgers = new Vendor("Burger Stand");
    DemoStation *ps4 = new DemoStation("PS4 Consoles");

    /** Building the Main Hall  */
    MainHall *mainHall = new MainHall("Main Hall");

    /**Build Main Hall  */
    /**Composite Pattern */
    mainHall->add(cosplayStage);
    mainHall->add(mainMedics);
    mainHall->add(john);

    /**Observer Pattern */
    mainHall->attach(cosplayStage);
    cosplayStage->setParent(mainHall);
    
    mainHall->attach(mainMedics);
    mainMedics->setParent(mainHall);
    
    mainHall->attach(john);
    john->setParent(mainHall);

    /**Build GamingZone */
    GamingZone *gameZone = new GamingZone("Gamer Den");
    /** Composite Pattern */
    gameZone->add(ps4);

    /**Observer Pattern */
    gameZone->attach(ps4);
    ps4->setParent(gameZone);

    /**Build the Vendor Zone */

    /**Observer Pattern */
    VendorZone *vendorArea = new VendorZone("Food Area");

    /**ConcreteSubject */
    EventControl *manager = new EventControl("Comic Con");
    
    manager->attach(mainHall);
    mainHall->setParent(manager);
    
    manager->attach(gameZone);
    gameZone->setParent(manager);
    
    manager->attach(vendorArea);
    vendorArea->setParent(manager);

    EventNotice fullNotice(NoticeType::CAPACITY_ALERT, "Comic Con is reaching maximum capacity.");
    manager->alert(fullNotice);

    std::cout << "=========================\n" ;

    EventNotice fullNotice2(NoticeType::WEATHER_ALERT, "Lots of rain.");
    manager->alert(fullNotice2);

    /** @todo Cascading event notification */

    /** @todo Conditional event response and Composite behaviour */

    /** @todo Signature event scenario */
    return 0;
}