#pragma once

#include <Thor/Vectors.hpp>
#include "Subject.h"

class GameEntity;
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

	static bool isColliding(Circle t_ball, Circle t_entityCircle);
	static bool isColliding(Circle t_ball, AABB t_entityAABB);
	static bool isColliding(Circle t_ball, Line t_entityLine);

private:

	/// <summary>
	/// @brief Get the distance between two points in 2D
	/// </summary>
	/// <param name="t_p1">First point</param>
	/// <param name="t_p2">Second point</param>
	/// <returns>length as a float</returns>
	static float getDistance(sf::Vector2f t_p1, sf::Vector2f t_p2);
};

#include "GameEntity.h"
#include "Ball.h"