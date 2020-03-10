#pragma once

#include "GameEntity.h"

class Flipper : public GameEntity
{
public:

	~Flipper() = default;

	/// <summary>
	/// @brief Updates the flipper along with the game loop
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	virtual void update(sf::Time t_dTime) = 0;

	/// <summary>
	/// @brief Returns the flipper shape
	/// </summary>
	/// <param name="t_window"></param>
	virtual sf::RectangleShape getShape() = 0;

	/// <summary>
	/// @brief Sets the position of the flipper
	/// </summary>
	/// <param name="t_pos"></param>
	virtual void setPosition(sf::Vector2f t_pos) = 0;

	/// <summary>
	/// @brief Returns the position of the flipper
	/// </summary>
	/// <returns></returns>
	virtual const sf::Vector2f getPosition() const = 0;

	/// <summary>
	/// @brief Returns the bounds of our line
	/// </summary>
	/// <returns></returns>
	virtual Line const& getBounds() const = 0;

	/// <summary>
	/// @brief 'Flicks' our flipper up to hit the ball
	/// </summary>
	virtual void flick() = 0;

protected:

	/// <summary>
	/// @brief Moves our flipper up or down, depending on its phase
	/// </summary>
	virtual void move() = 0;

	virtual void setupSprite() = 0;
	virtual void setupBoundingBox() = 0;
};