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
			if (sf::Keyboard::Left == event.key.code)
			{
				// If we're about to go below zero, go to the end of the list instead
				(temp_screenIndex > 0) ? temp_screenIndex-- : temp_screenIndex = temp_NUM_SCREENS;

				m_screenManager->setScreen(temp_screenTypeVector.at(temp_screenIndex % temp_NUM_SCREENS));
			}
			// Move to the next screen in the list
			if (sf::Keyboard::Right == event.key.code)
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