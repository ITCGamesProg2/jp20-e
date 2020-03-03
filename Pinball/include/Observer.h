#pragma once
// Abstract Class

#include "Obstacle.h"
#include "Event.h"

class Observer
{
public:
	virtual ~Observer() {}

	virtual void onNotify(const Obstacle& t_obstacle, Event t_event) = 0;
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