#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include <string>
#include "EventComponent.h"
#include "EventObserver.h"
#include "EventSubject.h"
#include "EventNotice.h"

class EventUnit : public EventComponent, EventObserver {

private:
	EventSubject* parent;
	std::string name;
	EventNotice currentNotice;

public:
	EventUnit(std::string name);

	virtual void update() override;

	virtual void add(EventComponent* cmp) override;

	virtual void remove(EventComponent* cmp) override;

	EventUnit();

	void setParent(EventSubject* par);

	virtual ~EventUnit() override = default;
};

#endif
