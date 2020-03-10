#include "MushroomBumper.h"

MushroomBumper::MushroomBumper() :
	m_radius(20.0f)
{
	setupSprite();
	setupBoundingBox();
}

///////////////////////////////////////////////////////////////

void MushroomBumper::setPosition(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
	m_boundingBox.p = t_pos;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f MushroomBumper::getPosition() const
{
	return m_body.getPosition();
}

///////////////////////////////////////////////////////////////

sf::CircleShape MushroomBumper::getSprite()
{
	return m_body;
}

///////////////////////////////////////////////////////////////

Circle const& MushroomBumper::getBounds() const
{
	return m_boundingBox;
}

///////////////////////////////////////////////////////////////

void MushroomBumper::setupSprite()
{
	m_body.setRadius(m_radius);
	m_body.setFillColor(sf::Color::Magenta);
	m_body.setOrigin(m_radius, m_radius);
}

///////////////////////////////////////////////////////////////

void MushroomBumper::setupBoundingBox()
{
	m_boundingBox.r = m_radius;
	m_boundingBox.p = m_body.getPosition();
}
