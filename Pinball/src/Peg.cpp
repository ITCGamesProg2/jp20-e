#include "Peg.h"

Peg::Peg() :
	m_radius{3.0f}
{
	setupSprite();
	setupBoundingBox();
}

///////////////////////////////////////////////////////////////

void Peg::setupSprite()
{
	m_body.setFillColor(sf::Color::Black);
	m_body.setRadius(m_radius);

	m_body.setOrigin({ m_radius,m_radius });
}

///////////////////////////////////////////////////////////////

void Peg::setupBoundingBox()
{
	// Set position
	m_boundingBox.x = m_position.x;
	m_boundingBox.y = m_position.y;

	// Set radius
	m_boundingBox.r = m_radius;
}


///////////////////////////////////////////////////////////////

void Peg::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
	m_body.setPosition(m_position);

	m_boundingBox.x = m_position.x;
	m_boundingBox.y = m_position.y;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Peg::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

sf::CircleShape Peg::getSprite()
{
	m_body.setPosition(m_position);
	return m_body;
}

///////////////////////////////////////////////////////////////

Circle const& Peg::getBounds() const
{
	return m_boundingBox;
}