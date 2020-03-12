#include "License.h"

License::License(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{t_manager}
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("LICENSE");

	f_switchScreen = t_switchScreen;

}

///////////////////////////////////////////////////////////////

void License::processEvents(sf::Event t_event, Xbox360Controller& t_controller)
{
	
}

///////////////////////////////////////////////////////////////

void License::update(sf::Time t_dTime, Xbox360Controller& t_controller)
{
	m_cumulativeTime += t_dTime;

	if (m_cumulativeTime.asSeconds() >= 5.0f)
	{
		f_switchScreen(m_manager, ScreenType::SPLASH);
	}
}

///////////////////////////////////////////////////////////////

void License::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}