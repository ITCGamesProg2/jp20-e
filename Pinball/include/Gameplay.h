#pragma once

#include "CollisionHandler.h"
#include "BaseScreen.h"
#include "Flipper.h"
#include "Ball.h"
#include "Peg.h"
#include <vector>
#include "Barrier.h"

class ScreenManager;

class Gameplay :
	public BaseScreen
{
public:
	Gameplay(sf::Font& t_font, std::function<void(ScreenManager*, ScreenType t_type)> t_switchScreen, ScreenManager* t_manager);
	~Gameplay() = default;

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

	/// <summary>
	/// @brief Respawns the ball at its original position
	/// </summary>
	void respawnBall();

private:

	std::function<void(ScreenManager*, ScreenType t_type)> f_switchScreen;

	sf::Font& m_font;

	sf::Text m_text;

	Flipper m_flipper;

	Ball m_ball;
	std::vector<Peg> m_pegs;
	Barrier m_barriers;

	const sf::Vector2f ORIGINAL_BALL_POS{ 300.0f, 0.0f };
	const sf::Vector2f ORIGINAL_BALL_VELOCITY{ 0.0f, 0.0f };
	const float BOTTOM_OF_SCREEN{ 900.0f };

	ScreenManager* m_manager;
};

#include "ScreenManager.h"