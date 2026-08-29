#ifndef EVENTOBSERVER_H
#define EVENTOBSERVER_H

class EventObserver {


public:
	EventObserver();

	virtual void update() = 0;
	virtual ~EventObserver() = default;
};

#endif
