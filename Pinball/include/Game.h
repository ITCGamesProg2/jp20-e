#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include <iostream>

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

	bool m_exitGame;

	sf::Font m_font;
};
#endif