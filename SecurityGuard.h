#ifndef SECURITYGUARD_H
#define SECURITYGUARD_H

#include "EventUnit.h"
#include <string>

/**
 * @file SecurityGuard.h
 * @brief A concrete leaf component representing a security guard unit.
 *
 * This class inherits from EventUnit and implements specific
 * print behaviors for various event notifications, acting as a
 * distinct participant in the Composite and Observer patterns.
 */
class SecurityGuard : public EventUnit
{
public:
    /**
     * @brief Parameterized constructor for SecurityGuard.
     *
     * @param name The string identifier for this specific security unit.
     * @param capacity The capacity of this specific unit
     */
    SecurityGuard(std::string name, int capacity);

    /**
     * @brief Executes the specific reaction of the security guard to the current notice.
     *
     * This method overrides the pure virtual print() method from EventUnit.
     * It uses the current notice type to determine the appropriate security response.
     */
    virtual void print() override;
};

#endif