#include "Splash.h"

Splash::Splash(sf::Font& t_font) :
	m_font{ t_font }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("SPLASH");
}

///////////////////////////////////////////////////////////////

void Splash::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void Splash::update(sf::Time t_dTime)
{
}

///////////////////////////////////////////////////////////////

void Splash::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}