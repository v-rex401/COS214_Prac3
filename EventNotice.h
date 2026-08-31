#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>
/**
 * @brief enum NoticeType for the different notices
 * @author Jordan
 */
enum class NoticeType
{
	BEGIN,
	END,
	DELAYED,
	CAPACITY_ALERT,
	EVACUATE,
	FIRE,
	WEATHER_ALERT
};

class EventNotice
{

private:
	NoticeType type;
	std::string message;

public:
	/**
	 * @brief default constructor
	 */
	EventNotice();

	/**
	 * @brief parameterised constructor
	 */
	EventNotice(NoticeType type, std::string msg);

	/**
	 * @brief get for the enum
	 * @return NoticeType
	 */
	NoticeType getType();

	/**
	 * @brief get for the string message
	 * @return string message
	 */
	std::string getMsg();
};

#endif
