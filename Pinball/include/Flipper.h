#pragma once

#include "GameEntity.h"

class Flipper : public GameEntity
{
public:
	Flipper();

	~Flipper() = default;

	/// <summary>
	/// @brief Updates the flipper along with the game loop
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	void update(sf::Time t_dTime);

	/// <summary>
	/// @brief Returns the flipper shape
	/// </summary>
	/// <param name="t_window"></param>
	sf::RectangleShape getShape();

	/// <summary>
	/// @brief Sets the position of the flipper
	/// </summary>
	/// <param name="t_pos"></param>
	virtual void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// @brief Returns the position of the flipper
	/// </summary>
	/// <returns></returns>
	virtual const sf::Vector2f getPosition() const override;

	/// <summary>
	/// @brief 'Flicks' our flipper up to hit the ball
	/// </summary>
	void flick();

	/// <summary>
	/// @brief Returns the bounds of our line
	/// </summary>
	/// <returns></returns>
	Line const& getBounds() const override;

private:

	void setupSprite();
	void setupBoundingBox();

	/// <summary>
	/// @brief Moves our flipper up or down, depending on its phase
	/// </summary>
	void move();

	sf::RectangleShape m_body;

	float m_width;
	float m_height;

	// Keep track of whether or flipper should be actively moving up or now
	bool m_isFlicking;

	// Constraints for our rotation
	const float INITIAL_ROTATION;
	const float FINAL_ROTATION;

	// How many radians rotated off horizontal are we
	float m_currentRotation;

	Line m_boundingBox;
};