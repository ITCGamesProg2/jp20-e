#pragma once

#include "Subject.h"
#include "GameEntity.h"
#include "tinyc2.h"

class CollisionHandler : public Subject
{
public:

	CollisionHandler() = default;
	~CollisionHandler() = default;

	static bool isColliding(c2AABB const&, c2Capsule const&);
	static bool isColliding(c2AABB const&, c2Circle const&);
	static bool isColliding(c2AABB const&, c2Poly const&);
	static bool isColliding(c2Capsule const&, c2Circle const&);
	static bool isColliding(c2Capsule const&, c2Poly const&);
	static bool isColliding(c2Circle const&, c2Poly const&);

	// Self referential
	static bool isColliding(c2Circle const&, c2Circle const&);
	static bool isColliding(c2AABB const&, c2AABB const&);
	static bool isColliding(c2Capsule const&, c2Capsule const&);
	static bool isColliding(c2Poly const&, c2Poly const&);
};