#pragma once

#include <Thor/Vectors.hpp>
#include "Subject.h"

class GameEntity;
class Ball;

struct CollisionBox {};

struct Circle : public CollisionBox
{
	float x;
	float y;
	float r;
};

///////////////////////////////////////////////////////////////

struct Line : public CollisionBox
{
	float p1;
	float p2;
};

///////////////////////////////////////////////////////////////

struct AABB : public CollisionBox
{
	float x;
	float y;
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