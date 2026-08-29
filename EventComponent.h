#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

class EventComponent {


public:
	EventComponent();
	virtual void add(EventComponent* cmp) = 0;

	virtual void remove(EventComponent* cmp) = 0;

	virtual ~EventComponent() = default;
};

#endif
