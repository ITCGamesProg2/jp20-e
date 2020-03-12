#include "HighScore.h"

HighScore::HighScore(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{ t_manager }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("HIGHSCORE");

	f_switchScreen = t_switchScreen;
}

///////////////////////////////////////////////////////////////

void HighScore::processEvents(sf::Event t_event, Xbox360Controller& t_controller)
{
}

///////////////////////////////////////////////////////////////

void HighScore::update(sf::Time t_dTime, Xbox360Controller& t_controller)
{
}

///////////////////////////////////////////////////////////////

void HighScore::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}