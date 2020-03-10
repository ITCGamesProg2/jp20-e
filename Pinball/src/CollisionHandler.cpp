#include "CollisionHandler.h"

void CollisionHandler::resolveCollision(Ball& t_ball, Circle t_entityCircle)
{
	if (isColliding(t_ball.getBounds(), t_entityCircle))
	{
		sf::Vector2f surfaceOfContact{ getSurfaceOfContact(t_ball.getBounds().p, t_entityCircle.p) };
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), surfaceOfContact) };

		t_ball.setVelocity(finalVelocity);

		t_ball.setPosition(t_ball.getPosition() + (thor::unitVector(t_ball.getVelocity()) * 1.5f ));
	}
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

void CollisionHandler::resolveCollision(Ball& t_ball, Flipper& t_flipper)
{
	Line line{ t_flipper.getBounds() };

	// If our 'look-ahead' line intersects the flipper, OR our circle collides with the flipper
	if (isColliding(t_ball.getBounds(), line))
	{
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), {line.p2 - line.p1}) };
		
		t_ball.setVelocity(finalVelocity);

		contactSolver(t_ball, t_flipper.getBounds());
	}
}

///////////////////////////////////////////////////////////////

void CollisionHandler::resolveCollision(Ball& t_ball, Line t_entityLine)
{
	// If our 'look-ahead' line intersects the line, OR our circle collides with the line
	if (isColliding(t_ball.getBounds(), t_entityLine))
	{
		sf::Vector2f finalVelocity{ getReboundVector(t_ball.getVelocity(), {t_entityLine.p2 - t_entityLine.p1}) };

		t_ball.setVelocity(finalVelocity);

		contactSolver(t_ball, t_entityLine);
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

// CREDIT: This solution was inspired by Michael Rainsford's method

void CollisionHandler::contactSolver(Ball& t_ball, Line t_entityLine)
{
	// Get a vector along our line
	sf::Vector2f vectorAlongLine{ t_entityLine.p2 - t_entityLine.p1 };

	// Get a vector to the ball
	sf::Vector2f vectorToBall{ t_ball.getBounds().p - t_entityLine.p1 };

	// Get the angle between the line and the ball
	float angleToBall = thor::toRadian(thor::signedAngle(vectorToBall, vectorAlongLine));

	// How far along the line did the ball hit in local space?
	float distanceToCollision = thor::length(vectorToBall) * cosf(angleToBall);

	// Where did the ball hit in global space?
	sf::Vector2f pointOfCollision{ t_entityLine.p1 + (thor::unitVector(vectorAlongLine) * distanceToCollision) };

	// Line along which the ball needs to move to get away from the line
	sf::Vector2f perpendicular{ thor::perpendicularVector(vectorAlongLine) };

	// If the perpendicular goes through the bottom of the paddle, invert the Y
	if (perpendicular.y > 0.0f) perpendicular = -perpendicular;

	// What do we need to move the ball by to stop it colliding with the line?
	sf::Vector2f moveBy{ thor::unitVector(perpendicular) * t_ball.getBounds().r };

	sf::Vector2f newBallPos = pointOfCollision + moveBy;

	t_ball.setPosition(newBallPos);
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