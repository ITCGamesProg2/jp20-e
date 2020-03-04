#include "Ball.h"

Ball::Ball()
{

	m_ball.setRadius(10);
	m_ball.setFillColor(sf::Color::Black);

	m_velocity = { 00.0f, 0.0f };
	m_gravity = { 0.0f, 9.8f };
}

void Ball::update(sf::Time t_dTime)
{
	m_velocity.x += m_gravity.x * (t_dTime.asSeconds());
	m_velocity.y += m_gravity.y * (t_dTime.asSeconds());
	m_ball.move(m_velocity);
}

void Ball::setPosition(sf::Vector2f t_pos)
{
	m_ball.setPosition(t_pos);
}

const sf::Vector2f Ball::getPosition() const
{
	return m_ball.getPosition();
}

void Ball::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_ball);
}