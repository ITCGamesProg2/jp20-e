#include "License.h"

License::License(sf::Font& t_font) :
	m_font{ t_font }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("LICENSE");
}

///////////////////////////////////////////////////////////////

void License::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void License::update(sf::Time t_dTime)
{
}

///////////////////////////////////////////////////////////////

void License::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}