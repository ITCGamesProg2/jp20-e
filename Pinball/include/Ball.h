#pragma once

#include "GameEntity.h"

class Ball : public GameEntity
{
public:
	Ball();

	virtual void update(sf::Time t_dTime) override;
	virtual void render(sf::RenderWindow& t_window) override;

	virtual void setPosition(sf::Vector2f t_pos) override;
	virtual const sf::Vector2f  getPosition() const override;

private:
	sf::CircleShape m_ball;

	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
};