#include "Spring.h"

Spring::Spring()
{
}

///////////////////////////////////////////////////////////////

void Spring::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Spring::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

Line const& Spring::getBounds() const
{
	return m_boundingBox;
}

///////////////////////////////////////////////////////////////

void Spring::setupSprite()
{
}

///////////////////////////////////////////////////////////////

void Spring::setupBoundingBox()
{
}