#pragma once

#include "BaseScreen.h"

#include "License.h"
#include "Splash.h"
#include "MainMenu.h"
#include "Gameplay.h"
#include "Instructions.h"
#include "HighScore.h"
#include "Settings.h"
#include "Credits.h"

enum class ScreenType
{
	NONE,
	LICENSE,
	SPLASH,
	MAIN_MENU,
	GAMEPLAY,
	INSTRUCTIONS,
	HIGHSCORES,
	SETTINGS,
	CREDITS
};

class ScreenManager
{
public:


	ScreenManager() = default;
	~ScreenManager();

	void setScreen(ScreenType t_screen);

	/// <summary>
	/// @brief Passes SF events to the active screen
	/// </summary>
	/// <param name="t_event">SF::Event to pass</param>
	void processEvents(sf::Event t_event);

	/// <summary>
	/// @brief Calls the update loop on the active screen
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	void update(sf::Time t_dTime);

	/// <summary>
	/// @brief Calls the render function on the active screen
	/// </summary>
	/// <param name="t_window">SF::RenderWindow to draw to</param>
	void render(sf::RenderWindow& t_window);

private:

	License* m_licenseScreen = new License();
	Splash* m_splashScreen = new Splash();
	MainMenu* m_mainMenuScreen = new MainMenu();
	Gameplay* m_gameplayScreen = new Gameplay();
	Instructions* m_instructionsScreen = new Instructions();
	HighScore* m_highScoreScreen = new HighScore();
	Settings* m_settingsScreen = new Settings();
	Credits* m_creditsScreen = new Credits();

	BaseScreen* m_activeScreen;
};