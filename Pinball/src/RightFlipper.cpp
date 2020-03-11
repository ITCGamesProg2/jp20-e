#include "RightFlipper.h"

RightFlipper::RightFlipper() :
	m_width{ 100.0f },
	m_height{ 20.0f },
	INITIAL_ROTATION{ -0.5f },
	FINAL_ROTATION{ 0.6f },
	m_currentRotation{ INITIAL_ROTATION }
{
	setupSprite();
	setupBoundingBox();
}

///////////////////////////////////////////////////////////////

void RightFlipper::setupSprite()
{
	m_body.setSize({ m_width, m_height });
	m_body.setOrigin({ m_width, 0.0f });
	m_body.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////

void RightFlipper::setupBoundingBox()
{
	m_boundingBox.p1 = m_position - sf::Vector2f{ m_width,0.f };

	m_boundingBox.p2 = m_position;
}


///////////////////////////////////////////////////////////////

void RightFlipper::update(sf::Time t_dTime)
{
	m_boundingBox.p1 = m_position - sf::Vector2f{ m_width * cos(m_currentRotation), m_width * sin(m_currentRotation) };
	m_boundingBox.p2 = m_position;

	move();

	m_body.setRotation(m_currentRotation * (180.0f / 3.14159f));
}

///////////////////////////////////////////////////////////////

void RightFlipper::move()
{
	if (m_isFlicking)
	{
		// Move toward our final rotation
		(m_currentRotation < FINAL_ROTATION - 0.3f) ? m_currentRotation += 0.3f : m_currentRotation = FINAL_ROTATION;
	}
	else
	{
		// Move back toward our initial rotation
		(m_currentRotation > INITIAL_ROTATION + 0.1f) ? m_currentRotation -= 0.1f : m_currentRotation = INITIAL_ROTATION;
	}

	m_isFlicking = false;
}

///////////////////////////////////////////////////////////////

sf::RectangleShape RightFlipper::getShape()
{
	m_body.setPosition(m_position);
	return m_body;
}

///////////////////////////////////////////////////////////////

void RightFlipper::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f RightFlipper::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

Line const& RightFlipper::getBounds() const
{
	return m_boundingBox;
}

///////////////////////////////////////////////////////////////

void RightFlipper::flick()
{
	m_isFlicking = true;
}