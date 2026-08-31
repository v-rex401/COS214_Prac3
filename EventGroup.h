#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include <string>
#include <vector>
#include "EventComponent.h"
#include "EventSubject.h"
#include "EventObserver.h"

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
	EventGroup(std::string name, int total_cap);

	virtual void update() override;

	virtual EventNotice getNotice() override;

	void setParent(EventSubject *par);

	virtual void add(EventComponent *cmp) override;

	virtual void remove(EventComponent *cmp) override;

	virtual ~EventGroup() override;

	std::vector<EventComponent *> getComponents();

    int getCapacity();

private:
	EventGroup();
};

#endif
