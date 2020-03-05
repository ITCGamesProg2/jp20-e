#define TINYC2_IMPL

#include "CollisionHandler.h"

bool CollisionHandler::isColliding(c2AABB const& t_aabb, c2Capsule const& t_capsule)
{
	return c2AABBtoCapsule(t_aabb, t_capsule);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2AABB const& t_aabb, c2Circle const& t_circle)
{
	return c2CircletoAABB(t_circle, t_aabb);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2AABB const& t_aabb, c2Poly const& t_poly)
{
	return c2AABBtoPoly(t_aabb, &t_poly, nullptr);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2Capsule const& t_capsule, c2Circle const& t_circle)
{
	return c2CircletoCapsule(t_circle, t_capsule);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2Capsule const& t_capsule, c2Poly const& t_poly)
{
	return c2CapsuletoPoly(t_capsule, &t_poly, nullptr);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2Circle const& t_circle, c2Poly const& t_poly)
{
	return c2CircletoPoly(t_circle, &t_poly, nullptr);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2Circle const& t_circle1, c2Circle const& t_circle2)
{
	return c2CircletoCircle(t_circle1, t_circle2);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2AABB const& t_aabb1, c2AABB const& t_aabb2)
{
	return c2AABBtoAABB(t_aabb1, t_aabb2);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2Capsule const& t_capsule1, c2Capsule const& t_capsule2)
{
	return c2CapsuletoCapsule(t_capsule1, t_capsule2);
}

/////////////////////////////////////////////////////////////

bool CollisionHandler::isColliding(c2Poly const& t_poly1, c2Poly const& t_poly2)
{
	return c2PolytoPoly(&t_poly1, nullptr, &t_poly2, nullptr);
}
