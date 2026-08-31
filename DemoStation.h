#ifndef DEMOSTATION_H
#define DEMOSTATION_H

#include "EventUnit.h"
#include <string>

/**
 * @brief A concrete leaf component representing a gaming or tech demo station.
 * 
 * This class inherits from EventUnit and implements specific 
 * print behaviors for various event notifications, focusing on 
 * hardware management, player queues, and booth safety.
 */
class DemoStation : public EventUnit {
public:
    /**
     * @brief Parameterized constructor for DemoStation.
     * 
     * @param name The string identifier for this specific demo station unit.
     * @param capacity The capacity of this specific unit
     */
    DemoStation(std::string name, int capacity);

    /**
     * @brief Executes the specific reaction of the demo station to the current notice.
     * 
     * Overrides the pure virtual print() method from EventUnit.
     * Uses the current notice type to determine the appropriate booth response.
     */
    virtual void print() override; 
};

#endif