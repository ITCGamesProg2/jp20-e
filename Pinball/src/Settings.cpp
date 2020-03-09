#include "Settings.h"

Settings::Settings(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{ t_manager }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("SETTINGS");

	f_switchScreen = t_switchScreen;
}

///////////////////////////////////////////////////////////////

void Settings::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void Settings::update(sf::Time t_dTime)
{
}

///////////////////////////////////////////////////////////////

void Settings::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}