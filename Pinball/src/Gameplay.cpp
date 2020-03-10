#include "Gameplay.h"

Gameplay::Gameplay(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{ t_manager }
{
	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("GAMEPLAY");

	f_switchScreen = t_switchScreen;

	m_ball.setPosition(ORIGINAL_BALL_POS);

	m_barriers.setPositions(sf::Vector2f{ 50.0f, 50.0f }, sf::Vector2f{ 50.0f, 800.0f });

	float offset{ 0.0f };

	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Peg newPeg;
			newPeg.setPosition({ offset + 65.0f + (50.0f * j), 300.0f + (50.0f * i) });

			m_pegs.push_back(newPeg);
		}

		offset = (offset == 0.0f) ? 25.0f : 0.0f;
	}*/

	Peg newPeg;
	newPeg.setPosition({ 300.0f, 825.0f });
	m_pegs.push_back(newPeg);

	m_leftFlipper.setPosition({ 175.0f, 750.0f });
	m_rightFlipper.setPosition({ 425.0f, 750.0f });
}

///////////////////////////////////////////////////////////////

void Gameplay::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void Gameplay::update(sf::Time t_dTime)
{
	m_ball.update(t_dTime);
	m_leftFlipper.update(t_dTime);
	m_rightFlipper.update(t_dTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_leftFlipper.flick();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_rightFlipper.flick();
	}

	if (m_ball.getPosition().y >= BOTTOM_OF_SCREEN)
	{
		respawnBall();
	}
	
	for (Peg& p : m_pegs)
	{
		CollisionHandler::resolveCollision(m_ball, p.getBounds());
	}

	CollisionHandler::resolveCollision(m_ball, m_leftFlipper);
	CollisionHandler::resolveCollision(m_ball, m_rightFlipper);

	CollisionHandler::resolveCollision(m_ball, m_barriers.getBounds());

}

///////////////////////////////////////////////////////////////

void Gameplay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
	t_window.draw(m_ball.getShape());

	for (Peg& p : m_pegs)
	{
		t_window.draw(p.getSprite());
	}


	t_window.draw(m_leftFlipper.getShape());
	t_window.draw(m_rightFlipper.getShape());

	t_window.draw(m_barriers.getShape());
}

///////////////////////////////////////////////////////////////

void Gameplay::respawnBall()
{
	m_ball.setPosition(ORIGINAL_BALL_POS);
	m_ball.setVelocity(ORIGINAL_BALL_VELOCITY);
}