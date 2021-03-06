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
#include "TableBuilder.h"
#include "ScreenType.h"

class ScreenManager
{
public:


	ScreenManager(sf::Font& t_font);

	~ScreenManager();

	void setScreen(ScreenType t_screen);

	/// <summary>
	/// @brief Passes SF events to the active screen
	/// </summary>
	/// <param name="t_event">SF::Event to pass</param>
	void processEvents(sf::Event t_event, Xbox360Controller& t_controller);

	/// <summary>
	/// @brief Calls the update loop on the active screen
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	void update(sf::Time t_dTime, Xbox360Controller& t_controller);

	/// <summary>
	/// @brief Calls the render function on the active screen
	/// </summary>
	/// <param name="t_window">SF::RenderWindow to draw to</param>
	void render(sf::RenderWindow& t_window);

private:

	License* m_licenseScreen;
	Splash* m_splashScreen;
	MainMenu* m_mainMenuScreen;
	Gameplay* m_gameplayScreen;
	Instructions* m_instructionsScreen;
	HighScore* m_highScoreScreen;
	Settings* m_settingsScreen;
	Credits* m_creditsScreen;
	TableBuilder* m_tableBuilderScreen;
	BaseScreen* m_activeScreen;

	sf::Font& m_font;

	std::function<void(ScreenManager*, ScreenType t_type)> f_switchScreen;
};