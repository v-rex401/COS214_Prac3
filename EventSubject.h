#ifndef EVENTSUBJECT_H
#define EVENTSUBJECT_H

#include <string>
#include <vector>
#include "EventObserver.h"
#include "EventNotice.h"

class EventSubject {

private:
	std::vector<EventObserver*> observerList;

public:
	EventSubject();

	void attach(EventObserver* x);

	void detach(EventObserver* y);

	void notify();

	virtual EventNotice getNotice() = 0;
	
	virtual ~EventSubject() = default;
};

#endif
