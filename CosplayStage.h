#ifndef COSPLAYSTAGE_H
#define COSPLAYSTAGE_H

#include "EventUnit.h"
#include <string>

/**
 * @brief A concrete leaf component representing a cosplay stage or competition area.
 * @file CosplayStage.h
 * @author Robert
 * This class inherits from EventUnit and implements specific
 * print behaviors for various event notifications, focusing on
 * stage management, performers, and audience safety.
 */
class CosplayStage : public EventUnit
{
public:
    /**
     * @brief Parameterized constructor for CosplayStage.
     *
     * @param name The string identifier for this specific cosplay stage unit.
     * @param capacity The capacity of this specific unit
     */
    CosplayStage(std::string name, int capacity);

    /**
     * @brief Executes the specific reaction of the cosplay stage to the current notice.
     *
     * Overrides the pure virtual print() method from EventUnit.
     * Uses the current notice type to determine the appropriate stage management response.
     */
    virtual void print() override;
};

#endif