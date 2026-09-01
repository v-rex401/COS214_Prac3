#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>
/**
 * @file EventNotice.h
 * @brief Declares the EventNotice class and the NoticeType enum used to represent event notifications.
 */

/**
 * @brief EventNotice contains the message and notice type
 * @author Jordan
 */

/**
 * @brief enum NoticeType for all the different types of notices
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
