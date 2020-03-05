#pragma once

#include "GameEntity.h"

// Abstract class
class Obstacle : public GameEntity
{
public:

	virtual void setPosition(sf::Vector2f t_pos) = 0;

	virtual const sf::Vector2f getPosition() const = 0;
};