#include "Flipper.h"

Flipper::Flipper() : 
	m_width{100.0f},
	m_height{20.0f}
{
	setupSprite();
	setupBoundingBox();
}

///////////////////////////////////////////////////////////////

void Flipper::setupSprite()
{
	m_body.setSize({ m_width, m_height });
	m_body.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////

void Flipper::setupBoundingBox()
{
	m_boundingBox.w = m_width;
	m_boundingBox.h = m_height;
}

///////////////////////////////////////////////////////////////

void Flipper::update(sf::Time t_dTime)
{
	m_boundingBox.p = m_position;
}

///////////////////////////////////////////////////////////////

sf::RectangleShape Flipper::getShape()
{
	m_body.setPosition(m_position);
	return m_body;
}

///////////////////////////////////////////////////////////////

void Flipper::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
	m_boundingBox.p = m_position;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Flipper::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

AABB const& Flipper::getBounds() const
{
	return m_boundingBox;
}