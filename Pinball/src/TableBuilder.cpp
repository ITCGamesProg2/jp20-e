#include "TableBuilder.h"

TableBuilder::TableBuilder(sf::Font& t_font) :
	m_font(t_font)
{

	m_text.setFont(m_font);

	m_text.setCharacterSize(32U);
	m_text.setFillColor(sf::Color::Black);
	m_text.setString("TABLE BUILDER");

}

///////////////////////////////////////////////////////////////

void TableBuilder::processEvents(sf::Event t_events)
{
}

///////////////////////////////////////////////////////////////

void TableBuilder::update(sf::Time t_dTime)
{
}

///////////////////////////////////////////////////////////////

void TableBuilder::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}
