#include "EventComponent.h"
#include "EventControl.h"
#include "EventNotice.h"
#include "EventGroup.h"
/**
 * @file main.cpp
 * @class main class
 * @brief The Client runs here
 */

int main()
{
    /** @todo Build and register event */
    EventControl *manager = new EventControl("Comic Con");

    /** @todo Cascading event notification */

    /** @todo Conditional event response and Composite behaviour */

    /** @todo Signature event scenario */
    return 0;
}