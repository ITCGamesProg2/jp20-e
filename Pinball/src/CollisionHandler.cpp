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
	// make a circle encompassing the AABB
	Circle outerCircle;

	// center of AABB
	outerCircle.x = t_entityAABB.x + (t_entityAABB.w / 2.0f);
	outerCircle.y = t_entityAABB.y + (t_entityAABB.h / 2.0f);

	// half diagonal of AABB
	outerCircle.r = (thor::length(sf::Vector2f{ t_entityAABB.w, t_entityAABB.h }) / 2.0f);

	// if we're not colliding with the outer circle, we can't be colliding with the AABB
	if (!isColliding(t_ball, outerCircle))
	{
		return false;
	}

	// make a circle containted within the AABB
	Circle innerCircle(outerCircle);

	// half of the longest axis, draw a circle inside our box
	innerCircle.r = (std::max(t_entityAABB.w, t_entityAABB.h) / 2.0f);

	// if we're colliding with the inner circle, we're definitely colliding with the AABB
	if (isColliding(t_ball, innerCircle))
	{
		return true;
	}

	// check if the nearest point of our circle is inside the box
	float directionToBox{ thor::polarAngle((sf::Vector2f{innerCircle.x, innerCircle.y} -sf::Vector2f{t_ball.x, t_ball.y})) };

	// point on our circle which is closest to the center of the box
	sf::Vector2f nearestPoint = sf::Vector2f{ t_ball.x + (t_ball.r * cos(directionToBox)), t_ball.y + (t_ball.r * sin(directionToBox)) };

	// if we intersect in the x-axis
	if (nearestPoint.x > t_entityAABB.x && nearestPoint.x < (t_entityAABB.x + t_entityAABB.w))
	{
		// if we intersect in the y-axis
		if (nearestPoint.y > t_entityAABB.y && nearestPoint.y < (t_entityAABB.y + t_entityAABB.h))
		{
			return true;
		}
	}

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