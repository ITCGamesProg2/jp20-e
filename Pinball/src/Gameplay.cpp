#include "Gameplay.h"

Gameplay::Gameplay(sf::Font& t_font) :
	m_font{ t_font }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("GAMEPLAY");

	m_ball.setPosition(sf::Vector2f(300.0f, 0.0f));

	m_peg.setPosition({ 300.0f, 400.0f });
}

///////////////////////////////////////////////////////////////

void Gameplay::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void Gameplay::update(sf::Time t_dTime)
{
	m_ball.update(t_dTime);
}

///////////////////////////////////////////////////////////////

void Gameplay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
	t_window.draw(m_ball.getShape());
	t_window.draw(m_peg.getSprite());
}