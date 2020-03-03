#include "ScreenManager.h"

ScreenManager::ScreenManager(sf::Font& t_font) :
	m_activeScreen{nullptr},
	m_font{t_font}
{
	m_licenseScreen = new License(m_font);
	m_splashScreen = new Splash(m_font);
	m_mainMenuScreen = new MainMenu(m_font);
	m_gameplayScreen = new Gameplay(m_font);
	m_instructionsScreen = new Instructions(m_font);
	m_highScoreScreen = new HighScore(m_font);
	m_settingsScreen = new Settings(m_font);
	m_creditsScreen = new Credits(m_font);
}

///////////////////////////////////////////////////////////////

ScreenManager::~ScreenManager()
{
	delete m_licenseScreen;
	delete m_splashScreen;
	delete m_mainMenuScreen;
	delete m_gameplayScreen;
	delete m_instructionsScreen;
	delete m_highScoreScreen;
	delete m_settingsScreen;
	delete m_creditsScreen;
}

///////////////////////////////////////////////////////////////

void ScreenManager::setScreen(ScreenType t_screen)
{
	switch (t_screen)
	{
	case ScreenType::LICENSE:
		m_activeScreen = m_licenseScreen;
		break;
	case ScreenType::SPLASH:
		m_activeScreen = m_splashScreen;
		break;
	case ScreenType::MAIN_MENU:
		m_activeScreen = m_mainMenuScreen;
		break;
	case ScreenType::GAMEPLAY:
		m_activeScreen = m_gameplayScreen;
		break;
	case ScreenType::INSTRUCTIONS:
		m_activeScreen = m_instructionsScreen;
		break;
	case ScreenType::HIGHSCORES:
		m_activeScreen = m_highScoreScreen;
		break;
	case ScreenType::SETTINGS:
		m_activeScreen = m_settingsScreen;
		break;
	case ScreenType::CREDITS:
		m_activeScreen = m_creditsScreen;
		break;
	default:
		break;
	}
}

///////////////////////////////////////////////////////////////

void ScreenManager::processEvents(sf::Event t_event)
{
	m_activeScreen->processEvents(t_event);
}

///////////////////////////////////////////////////////////////

void ScreenManager::update(sf::Time t_dTime)
{
	m_activeScreen->update(t_dTime);
}

///////////////////////////////////////////////////////////////

void ScreenManager::render(sf::RenderWindow& t_window)
{
	m_activeScreen->render(t_window);
}