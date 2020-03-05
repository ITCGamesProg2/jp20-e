#pragma once
// Abstract class

#include "Observer.h"
#include "Event.h"
#include "Obstacle.h"
#include <vector>

class Subject
{
public:
	virtual ~Subject() {}

	/// <summary>
	/// @brief Adds an observer to our vector
	/// </summary>
	/// <param name="t_observer">ptr to observer to add</param>
	void addObserver(Observer* t_observer);

	/// <summary>
	/// @brief Searches for passed observer in our vector, removes it if there, does nothing if not
	/// </summary>
	/// <param name="t_observer">ptr to observer to remove</param>
	void removeObserver(Observer* t_observer);

private:

	std::vector<Observer*> m_observers;

protected:

	/// <summary>
	/// @brief Passes an event notification to all observers in our vector
	/// </summary>
	/// <param name="t_obstacle">Obstacle this event relates to</param>
	/// <param name="t_event">Type of event that occured</param>
	void notify(const GameEntity* t_entity, Event t_event);
};