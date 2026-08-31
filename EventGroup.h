#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include <string>
#include <vector>
#include "EventComponent.h"
#include "EventSubject.h"
#include "EventObserver.h"

/**
 * @file EventGroup.cpp
 * @brief Concrete Subject and Concrete Observer Implementation
 * @class EventGroup
 * @author Vashti
 *
 */
class EventGroup : public EventComponent, public EventSubject, public EventObserver
{

private:
	EventNotice currentNotice;
	std::vector<EventComponent *> componentList;
	EventSubject *parent;
	std::string name;
	int total_cap;
	int current_cap;

public:
	/**
	 * @brief Parameterized Constructor
	 */
	EventGroup(std::string name, int total_cap);

	/**
	 * @brief Pull update from the subject
	 * This behaviour applies to ConcreteObserver
	 */
	virtual void update() override;

	/**
	 * @brief This behaviour applied to ConcreteSubject
	 * @return currentNotice
	 */
	virtual EventNotice getNotice() override;

	/**
	 * @brief This behaviour applied to ConcreteSubject
	 */
	void setParent(EventSubject *par);

	/**
	 * @brief This behaviour applied to Composite Design Pattern
	 */
	virtual void add(EventComponent *cmp) override;

	/**
	 * @brief This behaviour applied to Composite Design Pattern
	 */
	virtual void remove(EventComponent *cmp) override;

	/**
	 * @brief EventGroup is responsible for its parent pointer
	 * and also the componentList it keeps
	 */
	virtual ~EventGroup() override;

	/**
	 * @brief
	 * @return componentList of type std::vector<EventComponent*>
	 */
	std::vector<EventComponent *> getComponents();

	/**
	 * @brief get the capacity of the group
	 * @return capacity
	 */
	int getCapacity();

private:
	EventGroup();
};

#endif
