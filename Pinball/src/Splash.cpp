#include "Splash.h"

Splash::Splash(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{ t_manager }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("SPLASH");

	f_switchScreen = t_switchScreen;
}

///////////////////////////////////////////////////////////////

void Splash::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		f_switchScreen(m_manager, ScreenType::MAIN_MENU);
	}
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