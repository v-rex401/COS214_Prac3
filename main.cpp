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
    // =========================================================
    // SETUP: INITIALIZING EVENT COMPONENTS
    // =========================================================
    
    /** Leaves */
    SecurityGuard *john = new SecurityGuard("John Doe", 5);
    MedicTeam *mainMedics = new MedicTeam("Main Hall Medics", 20);
    MedicTeam *vendorMedics = new MedicTeam("Vendor Zone Medics", 20);
    CosplayStage *cosplayStage = new CosplayStage("Cosplay in Main Hall", 100);
    Vendor *tacos = new Vendor("Taco Stand", 15);
    Vendor *burgers = new Vendor("Burger Stand", 15);
    DemoStation *ps4 = new DemoStation("PS4 Consoles", 30);

    /** Composites - Capacities adjusted to allow initial setup */
    MainHall *mainHall = new MainHall("Main Hall", 200); 
    GamingZone *gameZone = new GamingZone("Gamer Den", 50); 
    VendorZone *vendorArea = new VendorZone("Food Area", 60); 
    EventControl *manager = new EventControl("Comic Con", 500); 

    // =========================================================
    // SETUP: BUILDING THE COMPOSITE & OBSERVER TREES
    // =========================================================

    /** Build Main Hall */
    mainHall->add(cosplayStage); mainHall->attach(cosplayStage); cosplayStage->setParent(mainHall);
    mainHall->add(mainMedics);   mainHall->attach(mainMedics);   mainMedics->setParent(mainHall);
    mainHall->add(john);         mainHall->attach(john);         john->setParent(mainHall);

    /** Build Gaming Zone */
    gameZone->add(ps4);          gameZone->attach(ps4);          ps4->setParent(gameZone);

    /** Build Vendor Zone */
    vendorArea->add(tacos);        vendorArea->attach(tacos);        tacos->setParent(vendorArea);
    vendorArea->add(burgers);      vendorArea->attach(burgers);      burgers->setParent(vendorArea);
    vendorArea->add(vendorMedics); vendorArea->attach(vendorMedics); vendorMedics->setParent(vendorArea);

    /** Build Event Control (Root) */
    manager->add(mainHall);   manager->attach(mainHall);   mainHall->setParent(manager);
    manager->add(gameZone);   manager->attach(gameZone);   gameZone->setParent(manager);
    manager->add(vendorArea); manager->attach(vendorArea); vendorArea->setParent(manager);

    // =========================================================
    // PHASE 1: EVENT OPENS
    // =========================================================
    std::cout << "\n========== PHASE 1: EVENT OPENS ==========\n";
    EventNotice openNotice(NoticeType::BEGIN, "Comic Con 2026 is officially open!");
    manager->alert(openNotice);

    // =========================================================
    // PHASE 2: THE FIRE EMERGENCY
    // =========================================================
    std::cout << "\n========== PHASE 2: FIRE EMERGENCY ==========\n";
    EventNotice fireNotice(NoticeType::FIRE, "EMERGENCY: Fire detected near the Burger Stand!");
    manager->alert(fireNotice);

    // =========================================================
    // PHASE 3: RUNTIME REORGANIZATION (Task 4.2)
    // =========================================================
    std::cout << "\n========== PHASE 3: RUNTIME REORGANIZATION ==========\n";
    std::cout << "--> Transferring John Doe (Security) to Vendor Area to assist with the fire...\n";
    
    // Detach and remove from Main Hall
    mainHall->remove(john);
    mainHall->detach(john);
    
    // Add and attach to Vendor Zone
    vendorArea->add(john);
    vendorArea->attach(john);
    john->setParent(vendorArea);
    std::cout << "--> Transfer complete.\n";

    // =========================================================
    // PHASE 4: CAPACITY OVERFLOW (Task 4.3)
    // =========================================================
    std::cout << "\n========== PHASE 4: CAPACITY OVERFLOW ==========\n";
    std::cout << "--> Due to the fire, attendees are fleeing to the Gaming Zone.\n";
    std::cout << "--> Attempting to relocate the Cosplay Stage (Capacity: 100) to the Gamer Den (Max: 50)...\n";
    
    mainHall->remove(cosplayStage);
    mainHall->detach(cosplayStage);
    
    // ADD THIS LINE to prevent the dangling pointer:
    cosplayStage->setParent(nullptr); 

    // This will trigger your "Violates capacity check" output!
    gameZone->add(cosplayStage);
    
    
    mainHall->remove(cosplayStage);
    mainHall->detach(cosplayStage);

    // This will trigger your "Violates capacity check" output!
    gameZone->add(cosplayStage); 
    
    // Since it failed, we must send out a global capacity alert to control the crowd
    std::cout << "\n--> Dispatching Event-Wide Capacity Alert...\n";
    EventNotice capacityNotice(NoticeType::CAPACITY_ALERT, "CRITICAL: Comic Con zones are overflowing!");
    manager->alert(capacityNotice);

    std::cout << "\n========== END OF SIMULATION ==========\n";

    delete manager; 

    // CLEANUP: Destroy the orphaned Cosplay Stage that couldn't fit in the Gaming Zone
    delete cosplayStage;

    return 0;
}