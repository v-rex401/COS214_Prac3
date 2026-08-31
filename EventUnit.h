#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include <string>
#include "EventComponent.h"
#include "EventObserver.h"
#include "EventSubject.h"
#include "EventNotice.h"

/**
 * @brief An abstract base class for leaf participants in the Composite pattern.
 *
 * This class acts as an observer that executes an update command when it receives
 * a notification from the EventSubject it is attached to. Because it contains
 * a pure virtual print method, it cannot be instantiated directly.
 */
class EventUnit : public EventComponent, public EventObserver
{
protected:
     /**
      * @brief Capacity of the individual leaves
      *
      */
     int capacity;

private:
     /**
      * @brief Pointer to the parent subject (group/controller) that owns this unit
      *
      */
     EventSubject *parent;
     /** @brief The specific name or identifier of this unit
      *
      */
     std::string name;
     /** @brief The most recent notice pulled from the parent
      *
      */
     EventNotice currentNotice;

public:
     /**
      * @brief Parameterized constructor for EventUnit.
      *
      * @param name The string identifier for this specific unit.
      */
     EventUnit(std::string name, int capacity);

     /**
      * @brief Responds to a notification from the parent subject.
      *
      * Pulls the latest EventNotice from the parent
      */
     virtual void update() override;

     virtual void add(EventComponent *cmp) override;

     virtual void remove(EventComponent *cmp) override;

     /**
      * @brief Default constructor for EventUnit.
      */
     EventUnit();

     /**
      * @brief Links this unit to its hierarchical parent subject.
      *
      * @param par Pointer to the EventSubject acting as the parent.
      */

     void setParent(EventSubject *par);

     /**
      * @brief returns capacity of leaf
      */
     int getCapacity();

     /**
      * @brief Default virtual destructor to ensure safe polymorphic cleanup.
      */
     virtual ~EventUnit() override;

     /**
      * @brief Pure virtual method to print the unit's specific status or action.
      *
      * Forces all concrete leaf subclasses to define their own specific output behavior.
      */

     /** @brief Getter for the unit's name */
     std::string getName();

     /** @brief Getter for the unit's current notice */
     EventNotice getCurrentNotice();
};

#endif
