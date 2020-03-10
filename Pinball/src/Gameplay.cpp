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

	for (int i = 0; i < 5; i++)
	{
		m_barriers.push_back(Barrier());
	}

	m_barriers.at(0).setPositions(sf::Vector2f{ 50.0f, 50.0f }, sf::Vector2f{ 50.0f, 600.0f });
	m_barriers.at(1).setPositions(sf::Vector2f{ 50.0f, 600.0f }, sf::Vector2f{ 175.0f, 750.0f });
	m_barriers.at(2).setPositions(sf::Vector2f{ 550.0f, 50.0f }, sf::Vector2f{ 550.0f, 600.0f });
	m_barriers.at(3).setPositions(sf::Vector2f{ 550.0f, 600.0f }, sf::Vector2f{ 425.0f, 750.0f });
	m_barriers.at(4).setPositions(sf::Vector2f{ 50.0f, 50.0f }, sf::Vector2f{ 50.0f, 600.0f });

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

	for (int i = 0; i < 3; i++)
	{
		m_mushroomBumpers.push_back(MushroomBumper());
	}
	m_mushroomBumpers.at(0).setPosition(sf::Vector2f{ 150.0f, 200.0f });
	m_mushroomBumpers.at(1).setPosition(sf::Vector2f{ 450.0f, 200.0f });
	m_mushroomBumpers.at(2).setPosition(sf::Vector2f{ 300.0f, 400.0f });

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
	
	for (Barrier& b : m_barriers)
	{
		CollisionHandler::resolveCollision(m_ball, b.getBounds());
	}

	for (Peg& p : m_pegs)
	{
		CollisionHandler::resolveCollision(m_ball, p.getBounds());
	}

	for (MushroomBumper& m : m_mushroomBumpers)
	{
		CollisionHandler::resolveCollision(m_ball, m.getBounds());
	}

	CollisionHandler::resolveCollision(m_ball, m_leftFlipper);
	CollisionHandler::resolveCollision(m_ball, m_rightFlipper);
}

///////////////////////////////////////////////////////////////

void Gameplay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
	t_window.draw(m_ball.getShape());

	for (Barrier& b : m_barriers)
	{
		t_window.draw(b.getShape());
	}

	for (Peg& p : m_pegs)
	{
		t_window.draw(p.getSprite());
	}

	for (MushroomBumper& m : m_mushroomBumpers)
	{
		t_window.draw(m.getSprite());
	}

	t_window.draw(m_leftFlipper.getShape());
	t_window.draw(m_rightFlipper.getShape());
}

///////////////////////////////////////////////////////////////

void Gameplay::respawnBall()
{
	m_ball.setPosition(ORIGINAL_BALL_POS);
	m_ball.setVelocity(ORIGINAL_BALL_VELOCITY);
}