#include "LeftFlipper.h"

LeftFlipper::LeftFlipper() :
	m_width{ 100.0f },
	m_height{ 20.0f },
	INITIAL_ROTATION{ 0.5f },
	FINAL_ROTATION{ -0.6f },
	m_currentRotation{ INITIAL_ROTATION }
{
	setupSprite();
	setupBoundingBox();
}

///////////////////////////////////////////////////////////////

void LeftFlipper::setupSprite()
{
	m_body.setSize({ m_width, m_height });
	m_body.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////

void LeftFlipper::setupBoundingBox()
{
	m_boundingBox.p1 = m_position;

	m_boundingBox.p1 = m_position + sf::Vector2f{ m_width,0.f };
}


///////////////////////////////////////////////////////////////

void LeftFlipper::update(sf::Time t_dTime)
{
	m_boundingBox.p1 = m_position;
	m_boundingBox.p2 = m_position + sf::Vector2f{ m_width * cos(m_currentRotation), m_width * sin(m_currentRotation) };

	sf::Vector2f pos1 = m_boundingBox.p2;

	move();

	sf::Vector2f pos2 = m_position + sf::Vector2f{ m_width * cos(m_currentRotation), m_width * sin(m_currentRotation) };

	m_speed = thor::length(pos2 - pos1);

	m_body.setRotation(m_currentRotation * (180.0f / 3.14159f));
}

///////////////////////////////////////////////////////////////

void LeftFlipper::move()
{
	if (m_isFlicking)
	{
		// Move toward our final rotation
		(m_currentRotation > FINAL_ROTATION + 0.3f) ? m_currentRotation -= 0.3f : m_currentRotation = FINAL_ROTATION;
	}
	else
	{
		// Move back toward our initial rotation
		(m_currentRotation < INITIAL_ROTATION - 0.1f) ? m_currentRotation += 0.1f : m_currentRotation = INITIAL_ROTATION;
	}

	m_isFlicking = false;
}

///////////////////////////////////////////////////////////////

sf::RectangleShape LeftFlipper::getShape()
{
	m_body.setPosition(m_position);
	return m_body;
}

///////////////////////////////////////////////////////////////

void LeftFlipper::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f LeftFlipper::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

Line const& LeftFlipper::getBounds() const
{
	return m_boundingBox;
}

///////////////////////////////////////////////////////////////

float LeftFlipper::getSpeed() const
{
	return m_speed;
}

///////////////////////////////////////////////////////////////

void LeftFlipper::flick()
{
	m_isFlicking = true;
}