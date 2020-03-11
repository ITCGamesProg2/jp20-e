#pragma once
#include "GameEntity.h"

class Spring :
	public GameEntity
{
public:
	Spring();
	~Spring() = default;

	void setPosition(sf::Vector2f t_pos) override;
	const sf::Vector2f getPosition() const override;

	Line const& getBounds() const  override;
private:

	void setupSprite();
	void setupBoundingBox();

	sf::RectangleShape m_body;

	Line m_boundingBox;
};