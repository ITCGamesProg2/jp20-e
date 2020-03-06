#include "CollisionHandler.h"


bool CollisionHandler::isColliding(Circle t_ball, Circle t_entityCircle)
{
	// If the sum of the radii is greater than their distance, return true
	return (t_ball.r + t_entityCircle.r > 
			getDistance({ t_ball.x, t_ball.y }, { t_entityCircle.x, t_entityCircle.y }));
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(Circle t_ball, AABB t_entityAABB)
{
	return false;
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(Circle t_ball, Line t_entityLine)
{
	return false;
}

///////////////////////////////////////////////////////////////

float CollisionHandler::getDistance(sf::Vector2f t_p1, sf::Vector2f t_p2)
{
	return thor::length(t_p2 - t_p1);
}