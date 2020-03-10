#pragma once

#include <Thor/Vectors.hpp>
#include "Subject.h"

class GameEntity;
class Flipper;
class Ball;

struct CollisionBox {};

struct Circle : public CollisionBox
{
	sf::Vector2f p;
	float r;
};

///////////////////////////////////////////////////////////////

struct Line : public CollisionBox
{
	sf::Vector2f p1;
	sf::Vector2f p2;
};

///////////////////////////////////////////////////////////////

struct AABB : public CollisionBox
{
	sf::Vector2f p;
	float w;
	float h;
};

///////////////////////////////////////////////////////////////

class CollisionHandler : public Subject
{
public:

	CollisionHandler() = default;
	~CollisionHandler() = default;

	static void resolveCollision(Ball& t_ball, Circle t_entityCircle);
	static void resolveCollision(Ball& t_ball, AABB t_entityAABB);
	static void resolveCollision(Ball& t_ball, Line t_entityLine);
	static void resolveCollision(Ball& t_ball, Flipper& t_flipper);

private:

	static bool isColliding(Circle t_ball, Circle t_entityCircle);
	static bool isColliding(Circle t_ball, AABB t_entityAABB);
	static bool isColliding(Circle t_ball, Line t_entityLine);

	/// <summary>
	/// @brief Get a vector perpendicular to the contact normal
	/// </summary>
	static sf::Vector2f getSurfaceOfContact(sf::Vector2f t_ball, sf::Vector2f t_entity);

	/// <summary>
	/// @brief Get the vector along which our ball has rebounded
	/// </summary>
	static sf::Vector2f getReboundVector(sf::Vector2f t_velocity, sf::Vector2f t_surfaceOfContact);

	/// <summary>
	/// @brief Get the distance between two points in 2D
	/// </summary>
	/// <param name="t_p1">First point</param>
	/// <param name="t_p2">Second point</param>
	/// <returns>length as a float</returns>
	static float getDistance(sf::Vector2f t_p1, sf::Vector2f t_p2);

	/// <summary>
	/// @brief Return whether two lines, represented by four points, intersect
	/// </summary>
	static bool doIntersect(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2);

	/// <summary>
	/// @brief Given three colinear points p, q, r, the function checks if point q lies on line segment 'pr' 
	/// </summary>
	static bool onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r);

	/// <summary>
	/// @brief Check the orientation of 3 ordered points
	/// </summary>
	/// <returns>Return 0 if colinear, 1 if clockwise, 2 if counterclockwise</returns>
	static int orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r);

	// A line along the path our ball will travel between this frame and the next
	static Line m_lookAhead;
};

#include "GameEntity.h"
#include "Flipper.h"
#include "Ball.h"