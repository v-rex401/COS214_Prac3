#ifndef MEDICTEAM_H
#define MEDICTEAM_H

#include "EventUnit.h"
#include <string>

/**
 * @file MedicTeam.h
 * @brief A concrete leaf component representing a medical response team.
 *
 * This class inherits from EventUnit and implements specific
 * print behaviors for various event notifications, focusing on
 * first aid, triage, and attendee health safety.
 */
class MedicTeam : public EventUnit
{
public:
    /**
     * @brief Parameterized constructor for MedicTeam.
     *
     * @param name The string identifier for this specific medical unit.
     * @param capacity The capacity of this specific unit
     */
    MedicTeam(std::string name, int capacity);

    /**
     * @brief Executes the specific reaction of the medical team to the current notice.
     *
     * Overrides the pure virtual print() method from EventUnit.
     * Uses the current notice type to determine the appropriate medical response.
     */
    virtual void print() override;
};

#endif