#include "CollisionHandler.h"


void CollisionHandler::resolveCollision(Ball& t_ball, Circle t_entityCircle)
{
	if (isColliding(t_ball.getBounds(), t_entityCircle))
	{
		sf::Vector2f surfaceOfContact{ getSurfaceOfContact(t_ball.getBounds().p, t_entityCircle.p) };
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), surfaceOfContact) };

		t_ball.setVelocity(finalVelocity);
	}
}

///////////////////////////////////////////////////////////////

void CollisionHandler::resolveCollision(Ball& t_ball, AABB t_entityAABB)
{
	if (isColliding(t_ball.getBounds(), t_entityAABB))
	{

	}
}

///////////////////////////////////////////////////////////////

void CollisionHandler::resolveCollision(Ball& t_ball, Line t_entityLine)
{
	if (isColliding(t_ball.getBounds(), t_entityLine))
	{

	}
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(Circle t_ball, Circle t_entityCircle)
{
	// If the sum of the radii is greater than their distance, return true
	return (t_ball.r + t_entityCircle.r > 
			getDistance(t_ball.p, t_entityCircle.p));
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(Circle t_ball, AABB t_entityAABB)
{
	// make a circle encompassing the AABB
	Circle outerCircle;

	// center of AABB
	outerCircle.p.x = t_entityAABB.p.x + (t_entityAABB.w / 2.0f);
	outerCircle.p.y = t_entityAABB.p.y + (t_entityAABB.h / 2.0f);

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
	float directionToBox{ thor::polarAngle((innerCircle.p - t_ball.p)) };

	// point on our circle which is closest to the center of the box
	sf::Vector2f nearestPoint = sf::Vector2f{ t_ball.p.x + (t_ball.r * cos(directionToBox)), t_ball.p.y + (t_ball.r * sin(directionToBox)) };

	// if we intersect in the x-axis
	if (nearestPoint.x > t_entityAABB.p.x && nearestPoint.x < (t_entityAABB.p.x + t_entityAABB.w))
	{
		// if we intersect in the y-axis
		if (nearestPoint.y > t_entityAABB.p.y && nearestPoint.y < (t_entityAABB.p.y + t_entityAABB.h))
		{
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(Circle t_ball, Line t_entityLine)
{
	// Return line to origin
	sf::Vector2f offset = t_entityLine.p1;

	t_entityLine.p1 -= offset;
	t_entityLine.p2 -= offset;

	// Move ball with line
	t_ball.p += (-offset);

	// Get angle from origin
	float angle = thor::polarAngle(t_entityLine.p2);

	// Rotate line back to zero
	thor::rotate(t_entityLine.p2, -angle);

	// Rotate ball along with our frame of reference
	thor::rotate(t_ball.p, -angle);

	// If we align with the line along the x coordinate
	if (t_ball.p.x + t_ball.r > 0.0f && t_ball.p.x - t_ball.r < t_entityLine.p2.x)
	{
		if (t_ball.p.y - t_ball.r <= 0.0f && t_ball.p.y + t_ball.r >= 0.0f)
		{
			return true;
		}
	}

	return false;
}

///////////////////////////////////////////////////////////////

sf::Vector2f CollisionHandler::getSurfaceOfContact(sf::Vector2f t_ball, sf::Vector2f t_entity)
{
	return thor::perpendicularVector(t_entity - t_ball);
}

///////////////////////////////////////////////////////////////

sf::Vector2f CollisionHandler::getReboundVector(sf::Vector2f t_velocity, sf::Vector2f t_surfaceOfContact)
{
	// Get angle from origin
	float angle = thor::polarAngle(t_surfaceOfContact);

	// Rotate velocity by that angle
	thor::rotate(t_velocity, -angle);

	t_velocity.y *= -1.0f;

	// Rotate velocity back
	thor::rotate(t_velocity, angle);

	return t_velocity;
}

///////////////////////////////////////////////////////////////

float CollisionHandler::getDistance(sf::Vector2f t_p1, sf::Vector2f t_p2)
{
	return thor::length(t_p2 - t_p1);
}