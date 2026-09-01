#ifndef EVENTOBSERVER_H
#define EVENTOBSERVER_H

/**
 * @file EventObserver.h
 * @brief Declares the EventObserver abstract base class, the Observer participant of the Observer pattern.
 */
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
