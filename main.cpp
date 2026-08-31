#include "EventComponent.h"
#include "EventControl.h"
#include "EventNotice.h"
#include "EventGroup.h"
#include "MainHall.cpp"
#include "VendorZone.cpp"
#include "GamingZone.cpp"
#include "SecurityGuard.h"
#include "MedicTeam.h"
#include "CosplayStage.h"
#include "Vendor.h"
#include "DemoStation.h"

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

    /**Composite Pattern  */
    mainHall->add(cosplayStage);
    mainHall->add(mainMedics);
    mainHall->add(john);

    /**Observer Pattern */
    mainHall->attach(cosplayStage);
    mainHall->attach(mainMedics);
    mainHall->attach(john);

    GamingZone *gameZone = new GamingZone("Gamer Den");
    /** Composite Pattern */

    /**Observer Pattern */
    VendorZone *vendorArea = new VendorZone("Food Area");

    /**ConcreteSubject */
    EventControl *manager = new EventControl("Comic Con");

    manager->print();

    /** @todo Cascading event notification */

    /** @todo Conditional event response and Composite behaviour */

    /** @todo Signature event scenario */
    return 0;
}