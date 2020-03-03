#include "HighScore.h"

HighScore::HighScore(sf::Font& t_font) :
	m_font{ t_font }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("HIGHSCORE");
}

///////////////////////////////////////////////////////////////

void HighScore::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void HighScore::update(sf::Time t_dTime)
{
}

///////////////////////////////////////////////////////////////

void HighScore::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}