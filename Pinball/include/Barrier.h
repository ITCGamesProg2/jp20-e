#pragma once

#include "SFML/Graphics.hpp"
#include "CollisionHandler.h"

class Barrier
{
public:
	Barrier();

	/// <summary>
	/// @Brief Set up both of the positions for the line
	/// </summary>
	/// <param name="t_p1">First position</param>
	/// <param name="t_p2">Second Position</param>
	void setPositions(sf::Vector2f t_p1, sf::Vector2f t_p2);

	/// <summary>
	/// @Brief Return the first position of the line
	/// </summary>
	/// <returns></returns>
	sf::Vector2f getPos1();
	
	/// <summary>
	/// @Brief Return the second position of the line
	/// </summary>
	/// <returns></returns>
	sf::Vector2f getPos2();

	/// <summary>
	/// @Brief Returns the shape of the vertex array
	/// </summary>
	/// <returns></returns>
	sf::VertexArray getShape();

	/// <summary>
	/// @Brief Sets up the bounding box for collisions
	/// </summary>
	void setUpBoundingBox();

	/// <summary>
	/// @Brief Returns the bounding box to check for collisions 
	/// </summary>
	/// <returns></returns>
	Line const& getBounds() const;

private:
	
	sf::Vector2f m_pos1;
	sf::Vector2f m_pos2;

	sf::VertexArray m_line{sf::Lines};

	Line m_boundingBox;
};

