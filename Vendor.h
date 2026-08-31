#ifndef VENDOR_H
#define VENDOR_H

#include "EventUnit.h"
#include <string>

/**
 * @brief A concrete leaf component representing a merchandise or food vendor.
 * 
 * This class inherits from EventUnit and implements specific 
 * print behaviors for various event notifications, focusing on 
 * sales, customer queues, and securing inventory or cooking equipment.
 */
class Vendor : public EventUnit {
public:
    /**
     * @brief Parameterized constructor for Vendor.
     * 
     * @param name The string identifier for this specific vendor unit.
     * @param capacity The capacity of this specific unit
     */
    Vendor(std::string name, int capacity);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

    /**
     * @brief Executes the specific reaction of the vendor to the current notice.
     * 
     * Overrides the pure virtual print() method from EventUnit.
     * Uses the current notice type to determine the appropriate response.
     */
    virtual void print() override; 
};

#endif