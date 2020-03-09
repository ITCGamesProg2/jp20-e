#pragma once
#include "BaseScreen.h"

class ScreenManager;

class HighScore :
	public BaseScreen
{
public:
	HighScore(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager);
	~HighScore() = default;

	/// <summary>
	/// @brief Handles SFML events (keypress, mouseclick, etc.)
	/// </summary>
	/// <param name="t_event">sf::Event object to process</param>
	void processEvents(sf::Event t_event) override;

	/// <summary>
	/// @brief Handles 60fps update loop for this screen
	/// </summary>
	/// <param name="t_dTime">Time since last frame</param>
	void update(sf::Time t_dTime) override;

	/// <summary>
	/// @brief Handles render loop for this screen
	/// </summary>
	/// <param name="t_window">SF::RenderWindow to draw to</param>
	void render(sf::RenderWindow& t_window) override;

private:

	std::function<void(ScreenManager*, ScreenType t_type)> f_switchScreen;

	sf::Font& m_font;

	sf::Text m_text;

	ScreenManager* m_manager;
};

#include "ScreenManager.h"