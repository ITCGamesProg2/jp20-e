#include "CollisionHandler.h"

// CREDIT: Line intersection code inspired by an article on GeeksForGeeks, "orientation of 3 ordered points"

Line CollisionHandler::m_lookAhead;

void CollisionHandler::resolveCollision(Ball& t_ball, Circle t_entityCircle)
{
	m_lookAhead.p1 = t_ball.getPosition();
	m_lookAhead.p2 = m_lookAhead.p1 + t_ball.getVelocity();

	if (isColliding(t_ball.getBounds(), t_entityCircle))
	{
		sf::Vector2f surfaceOfContact{ getSurfaceOfContact(t_ball.getBounds().p, t_entityCircle.p) };
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), surfaceOfContact) };

		t_ball.setVelocity(finalVelocity);

		t_ball.setPosition(t_ball.getPosition() + (thor::unitVector(t_ball.getVelocity()) * 1.1f ));
	}

	m_lookAhead.p1 = { -1.0f,-1.0f };
	m_lookAhead.p2 = { -1.0f, 1.0f };
}

///////////////////////////////////////////////////////////////

void CollisionHandler::resolveCollision(Ball& t_ball, AABB t_entityAABB)
{
	if (isColliding(t_ball.getBounds(), t_entityAABB))
	{
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), sf::Vector2f{1.0f,0.0f} )};

		t_ball.setVelocity(finalVelocity);

		t_ball.setPosition(t_ball.getPosition() + (thor::unitVector(t_ball.getVelocity()) * 1.1f));
	}
}

///////////////////////////////////////////////////////////////

#include <iostream>

void CollisionHandler::resolveCollision(Ball& t_ball, Flipper& t_flipper)
{
	Line line{ t_flipper.getBounds() };

	// If magnitude of velocity isn't 0, get the unit vector (prevent dividing by 0)
	sf::Vector2f unit = (thor::length(t_ball.getVelocity()) != 0.0f) ? 
		thor::unitVector(t_ball.getVelocity()) : 
		sf::Vector2f{ 0.0f, 0.0f };

	// our ray starts at the position of the ball
	m_lookAhead.p1 = t_ball.getPosition();

	// And extends in the direction of our velocity to the combined speed of our ball + flipper per frame
	m_lookAhead.p2 = m_lookAhead.p1 + t_ball.getVelocity() + unit * t_flipper.getSpeed();

	// If our 'look-ahead' line intersects the flipper, OR our circle collides with the flipper
	if (doIntersect(m_lookAhead.p1, m_lookAhead.p2, line.p1, line.p2) || isColliding(t_ball.getBounds(), line))
	{
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), {line.p2 - line.p1}) };
		
		t_ball.setVelocity(finalVelocity);

		t_ball.setPosition(t_ball.getPosition() + (thor::unitVector(t_ball.getVelocity()) * 2.0f));
	}

	// After we've handled rebound, ensure it isn't sinking into flipper
	while (isColliding(t_ball.getBounds(), line))
	{
		t_ball.setPosition(t_ball.getPosition() + sf::Vector2f{0.0f, -0.01f});
	}
}

///////////////////////////////////////////////////////////////

void CollisionHandler::resolveCollision(Ball& t_ball, Line t_entityLine)
{
	// If our 'look-ahead' line intersects the line, OR our circle collides with the line
	if (doIntersect(m_lookAhead.p1, m_lookAhead.p2, t_entityLine.p1, t_entityLine.p2) || isColliding(t_ball.getBounds(), t_entityLine))
	{
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), {t_entityLine.p2 - t_entityLine.p1}) };

		t_ball.setVelocity(finalVelocity);

		t_ball.setPosition(t_ball.getPosition() + (thor::unitVector(t_ball.getVelocity()) * 2.0f));
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
	innerCircle.r = (std::min(t_entityAABB.w, t_entityAABB.h) / 2.0f);

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

	t_velocity.y *= -0.8f;

	// Rotate velocity back
	thor::rotate(t_velocity, angle);

	return t_velocity;
}

///////////////////////////////////////////////////////////////

float CollisionHandler::getDistance(sf::Vector2f t_p1, sf::Vector2f t_p2)
{
	return thor::length(t_p2 - t_p1);
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::doIntersect(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2)
{
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case 
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases 
}

///////////////////////////////////////////////////////////////

bool CollisionHandler::onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		return true;

	return false;
}

///////////////////////////////////////////////////////////////

int CollisionHandler::orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear 

	return (val > 0) ? 1 : 2; // clock or counterclock wise 
}