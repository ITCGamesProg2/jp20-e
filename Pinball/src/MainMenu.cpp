#include "MainMenu.h"

MainMenu::MainMenu(sf::Font& t_font) :
	m_font{ t_font }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("MAIN MENU");
}

///////////////////////////////////////////////////////////////

void MainMenu::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void MainMenu::update(sf::Time t_dTime)
{
}

///////////////////////////////////////////////////////////////

void MainMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}