#pragma once
#include "SFML/Graphics.hpp"
// Abstract class
class GameEntity
{
public:

	virtual void update() = 0;

	virtual void render() = 0;

	virtual void setPosition(sf::Vector2f t_pos) = 0;

	virtual const  sf::Vector2f getPosition() const = 0;



};