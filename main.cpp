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
    VendorZone *vendorArea = new VendorZone("Food Area");
    
    vendorArea->add(vendorMedics);
    vendorArea->add(tacos);
    vendorArea->add(burgers);

    vendorArea->attach(vendorMedics);
    vendorMedics->setParent(vendorArea);
    vendorArea->attach(tacos);
    tacos->setParent(vendorArea);
    vendorArea->attach(burgers);
    burgers->setParent(vendorArea);

    /**ConcreteSubject */
    EventControl *manager = new EventControl("Comic Con");
    
    manager->add(mainHall); 
    manager->attach(mainHall);
    mainHall->setParent(manager);
    
    manager->attach(gameZone);
    gameZone->setParent(manager);

    manager->remove(gameZone);
    manager->detach(gameZone);
    
    manager->add(vendorArea);
    manager->attach(vendorArea);
    vendorArea->setParent(manager);

    EventNotice fullNotice(NoticeType::CAPACITY_ALERT, "Comic Con is reaching maximum capacity.");
    manager->alert(fullNotice);

    std::cout << "=========================\nadding gamezon\n" ;
    manager->add(gameZone);
    manager->attach(gameZone);

    EventNotice fullNotice2(NoticeType::WEATHER_ALERT, "Lots of rain.");
    manager->alert(fullNotice2);

    /** @todo Cascading event notification */

    /** @todo Conditional event response and Composite behaviour */

    /** @todo Signature event scenario */
    /** @todo Signature event scenario */
    std::cout << "\n=== [SD4: SIGNATURE EVENT SCENARIO - FIRE EVACUATION] ===\n" << std::endl;

    // 1. The Incident Begins (Cascades to all zones)
    EventNotice fireNotice(NoticeType::FIRE, "Fire detected at the Burger Stand!");
    manager->alert(fireNotice);

    // 2. The Dynamic Structural Change (Observer leaving mid-execution)
    std::cout << "\n[EVENT CONTROL] Fire is spreading! Permanently detaching Vendor Zone from the event grid...\n" << std::endl;
    manager->remove(vendorArea);
    manager->detach(vendorArea);

    vendorArea->setParent(nullptr);//forget parent

    // 3. The Escalation (Cascades only to remaining zones)
    EventNotice evacNotice(NoticeType::EVACUATE, "Vendor Zone compromised! Evacuate remaining zones immediately!");
    manager->alert(evacNotice);

    // 4. The Shutdown (Final lockdown)
    EventNotice endNotice(NoticeType::END, "Venue cleared. Initiating final lockdown.");
    manager->alert(endNotice);
    
    delete manager;
    delete vendorArea;//cause it was removed for SD4

    return 0;
}