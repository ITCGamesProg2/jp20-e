#pragma once

#include "GameEntity.h"

class Ball : public GameEntity
{
public:
	Ball();

	/// <summary>
	/// @brief Does the update of the ball
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	virtual void update(sf::Time t_dTime) override;

	/// <summary>
	/// @brief Calls the render in order to draw the ball
	/// </summary>
	/// <param name="t_window">SF::RenderWindow to draw to</param>
	virtual void render(sf::RenderWindow& t_window) override;

	/// <summary>
	/// @brief Setting position of the ball
	/// </summary>
	/// <param name="t_pos"></param>
	virtual void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// @brief Returns the position of the ball
	/// </summary>
	/// <returns></returns>
	virtual const sf::Vector2f  getPosition() const override;

	/// <summary>
	/// @brief Sets the velocity of the ball
	/// </summary>
	/// <param name="t_velocity"></param>
	void setVelocity(sf::Vector2f t_velocity);

	/// <summary>
	/// @brief Returns the velocity of the ball
	/// </summary>
	/// <returns></returns>
	sf::Vector2f getVelocity();

	/// <summary>
	/// @brief Returns the bounds of the circle
	/// </summary>
	/// <returns></returns>
	c2Circle getBounds();

private:
	sf::CircleShape m_ball;

	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;

	c2Circle m_boundingCircle = c2Circle();
};