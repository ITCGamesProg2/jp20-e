#include "Barrier.h"

Barrier::Barrier()
{
}

void Barrier::setPosition(sf::Vector2f t_p1, sf::Vector2f t_p2)
{
	m_pos1 = t_p1;
	m_pos2 = t_p2;

	//m_laser.append(sf::Vertex{ sf::Vector2f{ 400.0f , 575.0f }, sf::Color::Red });
	m_line.append(sf::Vertex{ m_pos1 , sf::Color::Black });
	m_line.append(sf::Vertex{ m_pos2, sf::Color::Black });
}

sf::Vector2f Barrier::getPos1()
{
	return m_pos1;
}

sf::Vector2f Barrier::getPos2()
{
	return m_pos2;
}

sf::VertexArray Barrier::getShape()
{
	return m_line;
}
