#include "Gameplay.h"

Gameplay::Gameplay(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager) :
	m_font{ t_font },
	m_manager{ t_manager },
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

	for (auto& b : m_level.m_barriers)
	{
		Barrier newBarr;
		newBarr.setPositions(b.m_position1, b.m_position2);
		m_barriers.push_back(newBarr);
	}

	for (auto& obstacle : m_level.m_obstacles)
	{
		if (obstacle.m_type == "Peg")
		{
			Peg newPeg;
			newPeg.setPosition(obstacle.m_position);
			m_pegs.push_back(newPeg);
		}
		else if (obstacle.m_type == "MushroomBumper")
		{
			MushroomBumper newMushroom;
			newMushroom.setPosition(obstacle.m_position);
			m_mushroomBumpers.push_back(newMushroom);
		}
		else if (obstacle.m_type == "Target")
		{

		}
		else if (obstacle.m_type == "Hole")
		{

		}
		else if (obstacle.m_type == "Slingshot")
		{

		}
		else if (obstacle.m_type == "Spinner")
		{

		}
		else if (obstacle.m_type == "Stopper")
		{

		}
		else if (obstacle.m_type == "Rail")
		{

		}
	}

	m_leftFlipper.setPosition(m_level.m_leftFlipper.m_position);
	m_rightFlipper.setPosition(m_level.m_rightFlipper.m_position);

	m_spring.setPosition(m_level.m_spring.m_position);
}

///////////////////////////////////////////////////////////////

void Gameplay::processEvents(sf::Event t_event, Xbox360Controller& t_controller)
{
}

///////////////////////////////////////////////////////////////

void Gameplay::update(sf::Time t_dTime, Xbox360Controller& t_controller)
{
	m_spring.update(t_dTime);
	m_ball.update(t_dTime);
	m_leftFlipper.update(t_dTime);
	m_rightFlipper.update(t_dTime);

	if (t_controller.m_currentState.LB)
	{
		m_leftFlipper.flick();
	}

	if (t_controller.m_currentState.RB)
	{
		m_rightFlipper.flick();
	}

	if (t_controller.m_currentState.Y)
	{
		m_spring.pullBack();
	}

	if (m_ball.getPosition().y >= BOTTOM_OF_SCREEN)
	{
		respawnBall();
	}



	if (t_controller.m_currentState.X && !t_controller.m_previousState.X)
	{
		m_ball.setVelocity(sf::Vector2f(m_ball.getVelocity().x *-1.0f, m_ball.getVelocity().y * -1.0f));
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
	m_ball.setPosition(m_level.m_ball.m_position);
	m_ball.setVelocity(ORIGINAL_BALL_VELOCITY);
}