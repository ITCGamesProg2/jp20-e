#pragma once
// Abstract Class

#include "Obstacle.h"
#include "Event.h"

class Observer
{
public:
	virtual ~Observer() {}

	/// <summary>
	/// @brief Do something when an event is revieved
	/// </summary>
	/// <param name="t_entity">Game entity the event applies to</param>
	/// <param name="t_event">Type of event</param>
	virtual void onNotify(const GameEntity* t_entity, Event t_event) = 0;
	// E.g.
	// switch(t_event)
	// {
	//		case Event::BELL_HIT:
	//			bellSFX.play();
	//			break;
	//		case other:
	//			do something
	//			break;
	//		default:
	//			break;
	// }
private:
};