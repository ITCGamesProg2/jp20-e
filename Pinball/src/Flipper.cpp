#include "Flipper.h"

Flipper::Flipper() : 
	m_width{100.0f},
	m_height{20.0f},
	m_rotation{0.0f}
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
	m_boundingBox.p1 = m_position;
	m_boundingBox.p1 = m_position + sf::Vector2f{ m_width,0.f };
}

///////////////////////////////////////////////////////////////

void Flipper::update(sf::Time t_dTime)
{
	setPosition(m_position);
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

	m_boundingBox.p1 = m_position;
	m_boundingBox.p2 = m_position + sf::Vector2f{ m_width * cos(m_rotation), m_width * sin(m_rotation) };
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Flipper::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

Line const& Flipper::getBounds() const
{
	return m_boundingBox;
}