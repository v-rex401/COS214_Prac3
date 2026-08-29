#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

class EventNotice {

private:
	std::string type;
	std::string message;

public:
	EventNotice();

	EventNotice(std::string type, std::string msg);
};

#endif
