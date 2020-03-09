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
	m_boundingBox.p1 = m_position;
	m_boundingBox.p2 = m_position + sf::Vector2f{ m_width * cos(m_rotation), m_width * sin(m_rotation) };

	m_body.setRotation(m_rotation * (180.0f/3.14159));
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
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Flipper::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

void Flipper::rotate(float t_rotateBy)
{
	m_rotation += t_rotateBy;
}

///////////////////////////////////////////////////////////////

Line const& Flipper::getBounds() const
{
	return m_boundingBox;
}