#include "Spring.h"

Spring::Spring() :
	MIN_COMPRESSION{ 0.0f },
	MAX_COMPRESSION{ 90.0f },
	m_currentCompression{ MIN_COMPRESSION },
	m_width{50.0f},
	m_height{10.0f}
{
	setupSprite();
	setupBoundingBox();
}

///////////////////////////////////////////////////////////////

void Spring::setupSprite()
{
	m_body.setFillColor(sf::Color::Black);
	m_body.setSize({ m_width, m_height });
}

///////////////////////////////////////////////////////////////

void Spring::setupBoundingBox()
{
	m_boundingBox.p1 = m_position;
	m_boundingBox.p2 = m_position + sf::Vector2f{ m_width, 0.0f };
}

///////////////////////////////////////////////////////////////

void Spring::update(sf::Time t_dTime)
{
	updatePosition();
	updateBoundingBox();

	if (m_currentCompression > MIN_COMPRESSION + 15.0f)
	{
		m_currentCompression -= 15.0f;
	}
	else
	{
		m_currentCompression = MIN_COMPRESSION;
	}
}

///////////////////////////////////////////////////////////////

void Spring::pullBack()
{
	if (m_currentCompression < MAX_COMPRESSION - 17.0f)
	{
		m_currentCompression += 17.0f;
	}
	else
	{
		m_currentCompression = MAX_COMPRESSION;
	}
}

///////////////////////////////////////////////////////////////

void Spring::updatePosition()
{
	m_body.setPosition(m_position + sf::Vector2f{ 0.0f, m_currentCompression });
}

///////////////////////////////////////////////////////////////

void Spring::updateBoundingBox()
{
	m_boundingBox.p1 = m_position + sf::Vector2f{ 0.0f, m_currentCompression };
	m_boundingBox.p2 = m_position + sf::Vector2f{ m_width, m_currentCompression };
}

///////////////////////////////////////////////////////////////

sf::RectangleShape Spring::getShape()
{
	return m_body;
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