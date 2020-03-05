#pragma once
#include "Obstacle.h"
class Peg :
	public Obstacle
{
public:

	Peg();
	~Peg() = default;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="t_dTime"></param>
	void update(sf::Time t_dTime) override;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="t_pos"></param>
	void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const sf::Vector2f getPosition() const override;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const sf::CircleShape getSprite() const;

private:

	sf::CircleShape m_body;
};