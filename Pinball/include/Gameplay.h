#pragma once

#include <vector>

#include "CollisionHandler.h"
#include "BaseScreen.h"
#include "EntityType.h"
#include "LeftFlipper.h"
#include "RightFlipper.h"
#include "Ball.h"
#include "Peg.h"
#include "Barrier.h"
#include "MushroomBumper.h"
#include "LevelLoader.h"
#include "Spring.h"

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
	 void processEvents(sf::Event t_event, Xbox360Controller& t_controller) override;

	/// <summary>
	/// @brief Handles 60fps update loop for this screen
	/// </summary>
	/// <param name="t_dTime">Time since last frame</param>
	void update(sf::Time t_dTime, Xbox360Controller& t_controller) override;

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

	LeftFlipper m_leftFlipper;
	RightFlipper m_rightFlipper;

	Ball m_ball;
	std::vector<Peg> m_pegs;
	std::vector<Barrier> m_barriers;
	std::vector<MushroomBumper> m_mushroomBumpers;

	Spring m_spring;

	// on top of flipper
	//const sf::Vector2f ORIGINAL_BALL_POS{ 240.0f, 780.0f };

	const sf::Vector2f ORIGINAL_BALL_VELOCITY;
	const float BOTTOM_OF_SCREEN;

	ScreenManager* m_manager;

	LevelData m_level;
};

#include "ScreenManager.h"