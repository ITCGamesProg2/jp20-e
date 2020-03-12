#include "TableBuilder.h"

TableBuilder::TableBuilder(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font(t_font),
	m_manager{ t_manager }
{

	m_text.setFont(m_font);

	m_text.setCharacterSize(32U);
	m_text.setFillColor(sf::Color::Black);
	m_text.setString("TABLE BUILDER");

	f_switchScreen = t_switchScreen;
}

///////////////////////////////////////////////////////////////

void TableBuilder::processEvents(sf::Event t_events, Xbox360Controller& t_controller)
{
}

///////////////////////////////////////////////////////////////

void TableBuilder::update(sf::Time t_dTime, Xbox360Controller& t_controller)
{
}

///////////////////////////////////////////////////////////////

void TableBuilder::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}
