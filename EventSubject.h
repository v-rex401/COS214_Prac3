#ifndef EVENTSUBJECT_H
#define EVENTSUBJECT_H

#include <string>
#include <vector>
#include "EventObserver.h"
#include "EventNotice.h"

/**
 * @brief The abstract subject participant in the Observer pattern
 * 
 * This class defines the interface for managing event notifications.
 * It keeps a list of the interested observers but it does not strictly
 * own the memory of the observers registered to it.
 */

class EventSubject {

private:
	std::vector<EventObserver*> observerList;

public:
	/**
	 * @brief default constructor for EventSubject.
	 */
	EventSubject(){}

	/**
	 * @brief Registers an observer to pass future event notifications to
	 * 
	 * The subject stores a pointer to the observer but does not own it.
	 * The observer must remain alive when registered and detached before it is destroyed.
	 * 
	 * @param x Pointer to the observer to register. Must not be nullptr.
	 */
	void attach(EventObserver* x);

	/**
	 * @brief removes a previously registered observer from the notification list.
	 * 
	 * should the specified observer not be found, the method safely ignores the request.
	 * @param y Pointer to the observer to detach 
	 */
	void detach(EventObserver* y);


	/**
	 * @brief issues an update to all the registered observers.
	 * 
	 * It iterates through the observerList and invokes the update() method on 
	 * each of the attached observers
	 */
	void notify();

	/**
	 * @brief Retrieves the current active event notice.
	 * 
	 * @return EventNotice The current state or alert data
	 */
	virtual EventNotice getNotice() = 0;

	/**
	 * @brief virtual destructor to ensure safe polymorphic cleanup
	 */
	virtual ~EventSubject() = default;
};

#endif
