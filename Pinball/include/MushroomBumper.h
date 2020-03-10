#pragma once
#include "Obstacle.h"
class MushroomBumper :
	public Obstacle
{
public:
	MushroomBumper();

	//Getter and setter functions
	void setPosition(sf::Vector2f t_pos) override;
	const sf::Vector2f getPosition() const override;
	sf::CircleShape getSprite();

	Circle const& getBounds() const override;

private:

	void setupSprite();
	void setupBoundingBox();

	float m_radius;
	sf::CircleShape m_body;

	Circle m_boundingBox;

};

