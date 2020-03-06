#include "License.h"

License::License(sf::Font& t_font) :
	m_font{ t_font }
{
	m_text.setFont(m_font);
	m_text2.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(24U);
	m_text.setString("Made with SFML, Blender/Spriter and other stuff");
	m_text.setPosition(30.0f, 50.0f);

	m_ball.setFillColor(sf::Color::Red);
	m_ball.setRadius(40.0f);
	m_ball.setOrigin(m_ball.getGlobalBounds().width / 2, m_ball.getGlobalBounds().height / 2);
	m_ball.setPosition(-m_ball.getGlobalBounds().width, 520.0f + m_ball.getOrigin().y);

	m_text2.setFillColor(sf::Color::Black);
	m_text2.setCharacterSize(18U);
	m_text2.setString("Team E Shortest Intercourse\nTeam members:\nSzymon Piskorz, Ben Millar\nEthan Rennick, Niamh Andrews");
	m_text2.setPosition(-m_text2.getGlobalBounds().width + m_ball.getPosition().x - m_ball.getOrigin().x, m_ball.getPosition().y - m_ball.getOrigin().y);

	try
	{
		if (!m_texture.loadFromFile("ASSETS//IMAGES//ball.png"))
		{
			throw(std::exception("Error loading font"));
		}
	}
	catch (const std::exception& t_exception)
	{
		std::cout << t_exception.what() << std::endl;
	}

	m_ball.setTexture(&m_texture);

	m_background.setSize(sf::Vector2f(600.0f, 300.0f));
	m_background.setPosition(sf::Vector2f(0.0f, 600.0f));
	m_background.setFillColor(sf::Color::Green);

}

///////////////////////////////////////////////////////////////

void License::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void License::update(sf::Time t_dTime)
{
	m_ball.move(2.5f, 0.0f);
	m_ball.rotate(5.0f);
	m_text2.move(2.5f, 0.0f);
}

///////////////////////////////////////////////////////////////

void License::render(sf::RenderWindow& t_window)
{
	t_window.clear(sf::Color::Cyan);
	t_window.draw(m_background);
	t_window.draw(m_text);
	t_window.draw(m_text2);
	t_window.draw(m_ball);

}