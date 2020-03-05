#pragma once
#include "SFML/Graphics.hpp"
#include "tinyc2.h"
// Abstract class
class GameEntity
{
public:

	virtual void update(sf::Time t_dTime) = 0;

	virtual void setPosition(sf::Vector2f t_pos) = 0;

	virtual const  sf::Vector2f getPosition() const = 0;

protected:

	sf::Vector2f m_position;
};