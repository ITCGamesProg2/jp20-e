#include "Barrier.h"

Barrier::Barrier()
{
}

///////////////////////////////////////////////////////////////

void Barrier::setPositions(sf::Vector2f t_p1, sf::Vector2f t_p2)
{
	m_pos1 = t_p1;
	m_pos2 = t_p2;

	m_line.append(sf::Vertex{ m_pos1 , sf::Color::Black });
	m_line.append(sf::Vertex{ m_pos2, sf::Color::Black });

	setUpBoundingBox();
}

///////////////////////////////////////////////////////////////

sf::Vector2f Barrier::getPos1()
{
	return m_pos1;
}

///////////////////////////////////////////////////////////////

sf::Vector2f Barrier::getPos2()
{
	return m_pos2;
}

///////////////////////////////////////////////////////////////

sf::VertexArray Barrier::getShape()
{
	return m_line;
}

///////////////////////////////////////////////////////////////

void Barrier::setUpBoundingBox()
{
	m_boundingBox.p1 = m_pos1;
	m_boundingBox.p2 = m_pos2;
}

///////////////////////////////////////////////////////////////

Line const& Barrier::getBounds() const
{
	return m_boundingBox;
}
