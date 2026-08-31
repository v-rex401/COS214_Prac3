#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <string>
#include <vector>
#include "EventNotice.h"
#include "EventComponent.h"
#include "EventSubject.h"

class EventControl : public EventComponent, public EventSubject
{

private:
	EventNotice currentNotice;
	std::vector<EventComponent *> componentList;
	std::string name;
	int total_cap;
	int current_cap;

public:
	virtual EventNotice getNotice() override;

	EventControl(std::string name, int total_cap);

	EventControl();

	void alert(EventNotice noti);

	virtual void add(EventComponent *cmp) override;

	virtual void remove(EventComponent *cmp) override;

	virtual ~EventControl() override;

	void print() override;

	int getCapacity() override;
};

#endif
