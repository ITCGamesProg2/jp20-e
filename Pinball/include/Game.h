#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include <iostream>
#include <array>

class Game
{
public:

	// *** Default Constructor/Destructor ***
	Game();
	~Game();

	// *** Methods ***
	void run();

private:

	// *** Methods ***
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void loadFont();

	// *** Objects ***
	sf::RenderWindow m_window;

	ScreenManager* m_screenManager;

	// This code is used for switching between screens in order.
	// Later on we will do this based on logic, rather than a list
	static const int temp_NUM_SCREENS{ 8 };
	std::array<ScreenType, temp_NUM_SCREENS> temp_screenTypeVector;
	int temp_screenIndex{ 0 };

	bool m_exitGame;

	sf::Font m_font;
};
#endif