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

    /**Composites  */
    MainHall *mainHall = new MainHall("Main Hall");
    mainHall->add(cosplayStage);
    mainHall->attach(mainMedics);
    GamingZone *gameZone = new GamingZone("Gamer Den");
    VendorZone *vendorArea = new VendorZone("Food Area");

    /**ConcreteSubject */
    EventControl *manager = new EventControl("Comic Con");

    /** @todo Cascading event notification */

    /** @todo Conditional event response and Composite behaviour */

    /** @todo Signature event scenario */
    return 0;
}