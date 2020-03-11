#include "Ball.h"

Ball::Ball() :
	m_radius{10.0f}
{
	setupSprite();
	setupBoundingBox();

	m_velocity = { 00.0f, 0.0f };
	m_gravity = { 0.0f, 12.0f };
}

///////////////////////////////////////////////////////////////

void Ball::setupSprite()
{
	m_body.setFillColor(sf::Color::Black);
	m_body.setRadius(m_radius);

	m_body.setOrigin({ m_radius,m_radius });
}

///////////////////////////////////////////////////////////////

void Ball::setupBoundingBox()
{
	// Set position
	m_boundingBox.p = m_position;

	// Set radius
	m_boundingBox.r = m_radius;
}

///////////////////////////////////////////////////////////////

void Ball::update(sf::Time t_dTime)
{
	// Update velocity
	m_velocity.x += m_gravity.x * (t_dTime.asSeconds());
	m_velocity.y += m_gravity.y * (t_dTime.asSeconds());
	
	// Update position
	m_position += m_velocity;

	// Update bounding box
	m_boundingBox.p = m_position;
}

///////////////////////////////////////////////////////////////

sf::CircleShape Ball::getShape()
{
	m_body.setPosition(m_position);

	return m_body;
}

///////////////////////////////////////////////////////////////
 
void Ball::setPosition(sf::Vector2f t_pos)
{
	m_position = t_pos;
	m_body.setPosition(m_position);

	m_boundingBox.p = m_position;
}

///////////////////////////////////////////////////////////////

const sf::Vector2f Ball::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////

void Ball::setVelocity(sf::Vector2f t_velocity)
{
	m_velocity = t_velocity;
}

///////////////////////////////////////////////////////////////

sf::Vector2f Ball::getVelocity()
{
	return m_velocity;
}

///////////////////////////////////////////////////////////////

Circle const& Ball::getBounds() const
{
	return m_boundingBox;
}
