#include "Game.h"

/// <summary>
/// Default Constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 600, 900, 32 }, "SFML Game Window", sf::Style::Close },
	m_exitGame{ false }
{
	loadFont();

	m_screenManager = new ScreenManager(m_font);

	m_screenManager->setScreen(ScreenType::LICENSE);

	temp_screenTypeVector =
	{
		ScreenType::LICENSE,
		ScreenType::SPLASH,
		ScreenType::MAIN_MENU,
		ScreenType::GAMEPLAY,
		ScreenType::TABLEBUILDER,
		ScreenType::INSTRUCTIONS,
		ScreenType::HIGHSCORES,
		ScreenType::SETTINGS,
		ScreenType::CREDITS
	};
}

///////////////////////////////////////////////////////////////

/// <summary>
/// Default Destructor
/// </summary>
Game::~Game()
{
}

///////////////////////////////////////////////////////////////

/// <summary>
/// Main run method
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f); // run at 60fps
	srand(static_cast<unsigned>(time(nullptr)));

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

///////////////////////////////////////////////////////////////

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}

			// Move to the previous screen in the list. We use mod to avoid leaving the bounds of our array
			if (m_controller.m_currentState.DpadLeft)
			{
				// If we're about to go below zero, go to the end of the list instead
				(temp_screenIndex > 0) ? temp_screenIndex-- : temp_screenIndex = temp_NUM_SCREENS;

				m_screenManager->setScreen(temp_screenTypeVector.at(temp_screenIndex % temp_NUM_SCREENS));
			}
			// Move to the next screen in the list
			if (m_controller.m_currentState.DpadRight)
			{
				temp_screenIndex++;

				m_screenManager->setScreen(temp_screenTypeVector.at(temp_screenIndex % temp_NUM_SCREENS));
			}
		}

		m_screenManager->processEvents(event);
	}
}

///////////////////////////////////////////////////////////////

void Game::update(sf::Time t_deltaTime)
{
	m_controller.update();
#ifdef KEYBOARD_DEBUG
	processKeyboardInput();
#endif // KEYBOARD_DEBUG

	if (m_exitGame)
	{
		m_window.close();
	}

	m_screenManager->update(t_deltaTime);
}

///////////////////////////////////////////////////////////////

void Game::render()
{
	m_window.clear(sf::Color::White);

	m_screenManager->render(m_window);

	m_window.display();
}

///////////////////////////////////////////////////////////////

void Game::loadFont()
try
{
	if (!m_font.loadFromFile("ASSETS//FONTS//arial.ttf"))
	{
		throw(std::exception("Error loading font"));
	}
}
catch (const std::exception& t_exception)
{
	std::cout << t_exception.what() << std::endl;
}

#ifdef KEYBOARD_DEBUG

/////////////////////////////////////////////////////////////////////////////
void Game::processKeyboardInput()
{
	// Face buttons
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_controller.m_currentState.A = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		m_controller.m_currentState.X = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		m_controller.m_currentState.Y = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		m_controller.m_currentState.B = true;
	}

	// Dpad
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_controller.m_currentState.DpadLeft = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_controller.m_currentState.DpadRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_controller.m_currentState.DpadUp = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_controller.m_currentState.DpadDown = true;
	}

	// Bumper buttons
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		m_controller.m_currentState.LB = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
	{
		m_controller.m_currentState.RB = true;
	}
}

#endif // KEYBOARD_DEBUG

/////////////////////////////////////////////////////////////////////////////