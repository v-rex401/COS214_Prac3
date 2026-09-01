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
 * @brief contains main method to run client and demonstration
 */
/**
 * @class main class
 * @brief Program Entry Point
 */

int main()
{

    /**
     * @brief Leaves */
    SecurityGuard *john = new SecurityGuard("John Doe", 5);
    MedicTeam *mainMedics = new MedicTeam("Main Hall Medics", 20);
    MedicTeam *vendorMedics = new MedicTeam("Vendor Zone Medics", 20);
    CosplayStage *cosplayStage = new CosplayStage("Cosplay in Main Hall", 100);
    Vendor *tacos = new Vendor("Taco Stand", 15);
    Vendor *burgers = new Vendor("Burger Stand", 15);
    DemoStation *ps4 = new DemoStation("PS4 Consoles", 30);

    /** @brief Building the Main Hall  */
    MainHall *mainHall = new MainHall("Main Hall", 1000);

    /** @brief Build Main Hall  */
    /**Observer Pattern & Composite Pattern */
    mainHall->attach(cosplayStage);
    cosplayStage->setParent(mainHall);
    mainHall->add(cosplayStage);

    mainHall->attach(mainMedics);
    mainMedics->setParent(mainHall);
    mainHall->add(mainMedics);

    mainHall->attach(john);
    john->setParent(mainHall);
    mainHall->add(john);

    /** @brief Build GamingZone */
    GamingZone *gameZone = new GamingZone("Gamer Den", 1000);

    /** @brief Observer Pattern & Composite Pattern */
    gameZone->attach(ps4);
    ps4->setParent(gameZone);
    gameZone->add(ps4);

    /** @brief Build the Vendor Zone */
    VendorZone *vendorArea = new VendorZone("Food Area", 1000);

    vendorArea->attach(vendorMedics);
    vendorMedics->setParent(vendorArea);
    vendorArea->add(vendorMedics);

    vendorArea->attach(tacos);
    tacos->setParent(vendorArea);
    vendorArea->add(tacos);

    vendorArea->attach(burgers);
    burgers->setParent(vendorArea);
    vendorArea->add(burgers);

    /** @brief ConcreteSubject */
    EventControl *manager = new EventControl("Comic Con", 5000);

    manager->attach(mainHall);
    mainHall->setParent(manager);
    manager->add(mainHall);

    manager->attach(gameZone);
    gameZone->setParent(manager);

    manager->detach(gameZone);
    manager->remove(gameZone);

    manager->attach(vendorArea);
    vendorArea->setParent(manager);
    manager->add(vendorArea);

    EventNotice fullNotice(NoticeType::CAPACITY_ALERT, "Comic Con is reaching maximum capacity.");
    manager->alert(fullNotice);

    std::cout << "=========================\nadding gamezone\n";
    manager->attach(gameZone);
    manager->add(gameZone);

    EventNotice fullNotice2(NoticeType::WEATHER_ALERT, "Lots of rain.");
    manager->alert(fullNotice2);

    std::cout << "\n=== [SD4: SIGNATURE EVENT SCENARIO - FIRE EVACUATION] ===\n"
              << std::endl;

    // 1. The Incident Begins (Cascades to all zones)
    EventNotice fireNotice(NoticeType::FIRE, "Fire detected at the Burger Stand!");
    manager->alert(fireNotice);

    // 2. The Dynamic Structural Change (Observer leaving mid-execution)
    std::cout << "\n[EVENT CONTROL] Fire is spreading! Permanently detaching Vendor Zone from the event grid...\n"
              << std::endl;

    manager->detach(vendorArea);
    manager->remove(vendorArea);

    vendorArea->setParent(nullptr); // forget parent

    // 3. The Escalation (Cascades only to remaining zones)
    EventNotice evacNotice(NoticeType::EVACUATE, "Vendor Zone compromised! Evacuate remaining zones immediately!");
    manager->alert(evacNotice);

    // 4. The Shutdown (Final lockdown)
    EventNotice endNotice(NoticeType::END, "Venue cleared. Initiating final lockdown.");
    manager->alert(endNotice);

    delete manager;
    delete vendorArea; // cause it was removed for SD4

    return 0;
}