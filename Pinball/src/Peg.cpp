#include "Peg.h"

Peg::Peg()
{
	m_body.setFillColor(sf::Color::Black);
	m_body.setRadius(3.0f);

	m_body.setOrigin({ 3.0f,3.0f });
}

///////////////////////////////////////////////////////////////

void Peg::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
	m_body.setPosition(m_position);
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Peg::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

const sf::CircleShape Peg::getSprite() const
{
	return m_body;
}
