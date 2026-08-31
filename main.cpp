#include "EventComponent.h"
#include "EventControl.h"
#include "EventNotice.h"
#include "EventGroup.h"
#include "MainHall.cpp"
#include "VendorZone.cpp"
#include "GamingZone.cpp"
/**
 * @file main.cpp
 * @class main class
 * @brief The Client runs here
 */

int main()
{
    /** @todo Build and register event */
    EventControl *manager = new EventControl("Comic Con");
    MainHall *mainHall = new MainHall("Main Hall");
    /** @todo Cascading event notification */

    /** @todo Conditional event response and Composite behaviour */

    /** @todo Signature event scenario */
    return 0;
}