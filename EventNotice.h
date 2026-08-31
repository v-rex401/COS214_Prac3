#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

enum class NoticeType {
	BEGIN,
	END,
	DELAYED,
	CAPACITY_ALERT,
	EVACUATE,
	FIRE,
	WEATHER_ALERT
};


class EventNotice {

private:
	NoticeType type;
	std::string message;

public:
	EventNotice();

	EventNotice(NoticeType type, std::string msg);
	NoticeType getType();
	std::string getMsg();
};

#endif
