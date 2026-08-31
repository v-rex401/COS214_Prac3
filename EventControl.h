#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <string>
#include <vector>
#include "EventNotice.h"
#include "EventComponent.h"
#include "EventSubject.h"

/**
 * @brief EventControl is one of the concrete subjects
 * @author Vashti
 */

class EventControl : public EventComponent, public EventSubject
{

private:
	EventNotice currentNotice;
	std::vector<EventComponent *> componentList;
	std::string name;
	int total_cap;
	int current_cap;

public:
	/**
	 * @brief Return the current notice to be issued
	 * @return currentNotice
	 */
	virtual EventNotice getNotice() override;

	/**
	 * @brief parameterized Constructor
	 * @param name is the eventControl centres title
	 */
	EventControl(std::string name, int total_cap);

	/**
	 * @brief Default Constructor
	 */
	EventControl();

	/**
	 * @brief Send the alert to observers
	 * We are using the Pull Method. The currentNotice will be stored
	 * and all concrete observers will have to pull the update from Subject
	 */
	void alert(EventNotice noti);

	/**
	 * @brief Attach components to the componentList
	 * @param cmp the component to add to the list
	 */
	virtual void add(EventComponent *cmp) override;

	/**
	 * @brief remove the component from EventControl
	 * Event Control is a composite participant
	 * EventGroups are removed with this function by
	 * searching through the list of components associated with EventControl
	 */
	virtual void remove(EventComponent *cmp) override;

	/**
	 * @brief Destructor
	 */
	virtual ~EventControl() override;

	/**
	 * @brief Print out notifications and child components prints
	 */
	void print() override;

	/**
	 * @brief return the capacity
	 * @return capacity
	 */
	int getCapacity() override;
};

#endif
