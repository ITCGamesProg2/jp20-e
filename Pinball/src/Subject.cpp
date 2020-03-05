#include "Subject.h"

void Subject::addObserver(Observer* t_observer)
{
	m_observers.push_back(t_observer);
}

///////////////////////////////////////////////////////////////

void Subject::removeObserver(Observer* t_observer)
{
	for (std::vector<Observer*>::iterator i = m_observers.begin(); i < m_observers.end(); i++)
	{
		if (m_observers[i - m_observers.begin()] == t_observer)
		{
			m_observers.erase(i);
		}
	}
}

///////////////////////////////////////////////////////////////

void Subject::notify(const GameEntity& t_obstacle, Event t_event)
{
	for (Observer* o : m_observers)
	{
		o->onNotify(t_obstacle, t_event);
	}
}