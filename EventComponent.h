#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

/**
 * @brief Component participant in the GoF design pattern Composite
 * @author Jordan
 */
class EventComponent
{

public:
	/**
	 * @brief Default Constructor
	 */
	EventComponent() {}

	/**
	 * @brief add component to the tree hierarchy as a child
	 * @param cmp is the EventComponent to add
	 */
	virtual void add(EventComponent *cmp) = 0;

	/**
	 * @brief remove component from the tree hierarchy
	 * @param cmp is the component to remove
	 */
	virtual void remove(EventComponent *cmp) = 0;

	/**
	 * @brief Destructor is pure virtual
	 * hence the default
	 * same as the following:
	 * @code
	 * virtual ~EventComponent() = 0;
	 * @endcode
	 */
	virtual ~EventComponent() = default;

	/**
	 * @brief print pure virtual function
	 */
	virtual void print() = 0;

	/**
	 * @brief get the capacity of the component (pure virtual)
	 * @return capacity
	 */
	virtual int getCapacity() = 0;
};

#endif
