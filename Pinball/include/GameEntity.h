#pragma once
#include "SFML/Graphics.hpp"

struct CollisionBox;

// Abstract class
class GameEntity
{
public:

	virtual void setPosition(sf::Vector2f t_pos) = 0;
	virtual const sf::Vector2f getPosition() const = 0;

	virtual CollisionBox const& getBounds() const = 0;



protected:

	sf::Vector2f m_position;
};

#include "CollisionHandler.h"