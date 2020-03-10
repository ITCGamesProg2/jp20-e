#include "Flipper.h"

Flipper::Flipper() : 
	m_width{100.0f},
	m_height{20.0f},
	INITIAL_ROTATION{0.5f},
	FINAL_ROTATION{-0.6f},
	m_currentRotation{INITIAL_ROTATION},
	m_handedness{Handedness::LEFT}
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
	m_boundingBox.p2 = m_position + sf::Vector2f{ m_width * cos(m_currentRotation), m_width * sin(m_currentRotation) };

	move();

	m_body.setRotation(m_currentRotation * (180.0f/3.14159));
}

///////////////////////////////////////////////////////////////

void Flipper::move()
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

Line const& Flipper::getBounds() const
{
	return m_boundingBox;
}

///////////////////////////////////////////////////////////////

void Flipper::flick()
{
	m_isFlicking = true;
}

///////////////////////////////////////////////////////////////

void Flipper::setHandedness(Handedness t_handedness)
{
	m_handedness = t_handedness;

	switch (m_handedness)
	{
	case Handedness::LEFT:
		m_body.setOrigin({ 0.0f, 0.0f });
		break;
	case Handedness::RIGHT:
		m_body.setOrigin({ m_width, 0.0f });
		break;
	default:
		break;
	}
}