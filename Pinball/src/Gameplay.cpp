#include "Gameplay.h"

Gameplay::Gameplay(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{ t_manager },
	ORIGINAL_BALL_POS{ 575.0f, 100.0f },
	ORIGINAL_BALL_VELOCITY{ 0.0f,0.0f },
	BOTTOM_OF_SCREEN{ 900.0f }
{

	int currentLevel = 1;
	try
	{
		LevelLoader::load(currentLevel, m_level);
	}
	catch (std::exception& e)
	{
		std::cout << "Level loading failure." << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}


	m_text.setFont(m_font);

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(32U);
	m_text.setString("GAMEPLAY");

	f_switchScreen = t_switchScreen;

	m_ball.setPosition(m_level.m_ball.m_position);

	for (int i = 0; i < 25; i++)
	{
		m_barriers.push_back(Barrier());
	}

	m_barriers.at(0).setPositions(sf::Vector2f{ 50.0f, 50.0f }, sf::Vector2f{ 50.0f, 900.0f }); // left wall
	m_barriers.at(1).setPositions(sf::Vector2f{ 100.0f, 700.0f }, sf::Vector2f{ 175.0f, 750.0f }); // left slope
	m_barriers.at(2).setPositions(sf::Vector2f{ 100.0f, 650.0f }, sf::Vector2f{ 100.0f, 700.0f }); // left up
	m_barriers.at(3).setPositions(sf::Vector2f{ 50.0f, 750.0f }, sf::Vector2f{ 200.0f, 850.0f }); // left outlane bottom

	m_barriers.at(4).setPositions(sf::Vector2f{ 425.0f, 750.0f }, sf::Vector2f{ 500.0f, 700.0f }); // right slope
	m_barriers.at(5).setPositions(sf::Vector2f{ 550.0f, 900.0f }, sf::Vector2f{ 550.0f, 125.0f }); // right wall
	m_barriers.at(6).setPositions(sf::Vector2f{ 500.0f, 700.0f }, sf::Vector2f{ 500.0f, 650.0f }); // right up
	m_barriers.at(7).setPositions(sf::Vector2f{ 400.0f, 850.0f }, sf::Vector2f{ 550.0f, 750.0f }); // right outlane bottom

	m_barriers.at(8).setPositions(sf::Vector2f{ 550.0f, 50.0f }, sf::Vector2f{ 50.0f, 50.0f }); // ceiling

	m_barriers.at(9).setPositions(sf::Vector2f{ 50.0f, 400.0f }, sf::Vector2f{ 100.0f, 450.0f }); // left bumper top
	m_barriers.at(10).setPositions(sf::Vector2f{ 100.0f, 450.0f }, sf::Vector2f{ 100.0f, 550.0f }); // left bumper middle
	m_barriers.at(11).setPositions(sf::Vector2f{ 100.0f, 550.0f }, sf::Vector2f{ 50.0f, 600.0f }); // left bumper bottom

	m_barriers.at(12).setPositions(sf::Vector2f{ 500.0f, 450.0f }, sf::Vector2f{ 550.0f, 400.0f }); // right bumper top
	m_barriers.at(13).setPositions(sf::Vector2f{ 500.0f, 550.0f }, sf::Vector2f{ 500.0f, 450.0f }); // right bumper middle
	m_barriers.at(14).setPositions(sf::Vector2f{ 550.0f, 600.0f }, sf::Vector2f{ 500.0f, 550.0f }); // right bumper bottom

	m_barriers.at(15).setPositions(sf::Vector2f{ 200.0f, 850.0f }, sf::Vector2f{ 200.0f, 900.0f }); // left drain bottom
	m_barriers.at(16).setPositions(sf::Vector2f{ 400.0f, 900.0f }, sf::Vector2f{ 400.0f, 850.0f }); // right drain bottom

	m_barriers.at(17).setPositions(sf::Vector2f{ 174.0f, 750.0f }, sf::Vector2f{ 99.0f, 700.0f }); // left slope INV
	m_barriers.at(18).setPositions(sf::Vector2f{ 99.0f, 700.0f }, sf::Vector2f{ 99.0f, 650.0f }); // left up INV

	m_barriers.at(19).setPositions(sf::Vector2f{ 426.0f, 750.0f }, sf::Vector2f{ 501.0f, 700.0f }); // right slope INV
	m_barriers.at(20).setPositions(sf::Vector2f{ 501.0f, 700.0f }, sf::Vector2f{ 501.0f, 650.0f }); // right up INV

	m_barriers.at(21).setPositions(sf::Vector2f{ 550.0f, 800.0f }, sf::Vector2f{ 565.0f, 800.0f }); // left spring stopper
	m_barriers.at(22).setPositions(sf::Vector2f{ 585.0f, 800.0f }, sf::Vector2f{ 600.0f, 800.0f }); // right spring stopper

	m_barriers.at(23).setPositions(sf::Vector2f{ 600.0f, 900.0f }, sf::Vector2f{ 600.0f, 100.0f }); // far right wall
	m_barriers.at(24).setPositions(sf::Vector2f{ 600.0f, 100.0f }, sf::Vector2f{ 550.0f, 50.0f }); // top of spring angle

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

	m_spring.setPosition({ 550.0f, 800.0f });
}

///////////////////////////////////////////////////////////////

void Gameplay::processEvents(sf::Event t_event)
{
}

///////////////////////////////////////////////////////////////

void Gameplay::update(sf::Time t_dTime)
{
	m_spring.update(t_dTime);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_spring.pullBack();
	}

	if (m_ball.getPosition().y >= BOTTOM_OF_SCREEN)
	{
		respawnBall();
	}
	
	for (Barrier& b : m_barriers)
	{
		CollisionHandler::resolveCollision(m_ball, b.getBounds(), EntityType::Barrier);
	}

	for (Peg& p : m_pegs)
	{
		CollisionHandler::resolveCollision(m_ball, p.getBounds(), EntityType::Peg);
	}

	for (MushroomBumper& m : m_mushroomBumpers)
	{
		CollisionHandler::resolveCollision(m_ball, m.getBounds(), EntityType::MushroomBumper);
	}

	CollisionHandler::resolveCollision(m_ball, m_leftFlipper, EntityType::Flipper);
	CollisionHandler::resolveCollision(m_ball, m_rightFlipper, EntityType::Flipper);

	CollisionHandler::resolveCollision(m_ball, m_spring.getBounds(), EntityType::Spring);
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

	t_window.draw(m_spring.getShape());
}

///////////////////////////////////////////////////////////////

void Gameplay::respawnBall()
{
	m_ball.setPosition(ORIGINAL_BALL_POS);
	m_ball.setVelocity(ORIGINAL_BALL_VELOCITY);
}