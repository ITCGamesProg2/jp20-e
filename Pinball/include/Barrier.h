#pragma once

#include "SFML/Graphics.hpp"

class Barrier
{
public:
	Barrier();

	void setPosition(sf::Vector2f t_p1, sf::Vector2f t_p2);

	sf::Vector2f getPos1();

	sf::Vector2f getPos2();

	sf::VertexArray getShape();

private:
	
	sf::Vector2f m_pos1;
	sf::Vector2f m_pos2;

	sf::VertexArray m_line;
};

