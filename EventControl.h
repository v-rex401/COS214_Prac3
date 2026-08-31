#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <string>
#include <vector>
#include "EventNotice.h"
#include "EventComponent.h"
#include "EventSubject.h"

class EventControl : public EventComponent, EventSubject
{

private:
	EventNotice currentNotice;
	std::vector<EventComponent *> componentList;
	std::string name;

public:
	virtual EventNotice getNotice() override;

	EventControl(std::string name);

	EventControl();

	void alert(EventNotice noti);

	virtual void add(EventComponent *cmp) override;

	virtual void remove(EventComponent *cmp) override;

	virtual ~EventControl() override;

	void print() override;
};

#endif
