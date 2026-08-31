#ifndef EVENTOBSERVER_H
#define EVENTOBSERVER_H

/**
 * @brief Observer participant of the GoF design pattern Observer
 * @author Jordan
 */
class EventObserver
{

public:
	/**
	 * @brief Default Constructor
	 */
	EventObserver() {}

	/**
	 * @brief pure virtual function to be implemented in child classes
	 */
	virtual void update() = 0;

	/**
	 * @brief Destructor
	 */
	virtual ~EventObserver() {}
};

#endif
