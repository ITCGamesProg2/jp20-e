#pragma once
#include "Obstacle.h"
class Peg :
	public Obstacle
{
public:

	Peg();
	~Peg() = default;

	// Getters/Setters
	void setPosition(sf::Vector2f t_pos) override;
	const sf::Vector2f getPosition() const override;
	const sf::CircleShape getSprite() const;

private:

	sf::CircleShape m_body;
};