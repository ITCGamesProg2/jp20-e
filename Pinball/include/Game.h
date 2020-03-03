#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

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

	// *** Objects ***
	sf::RenderWindow m_window;

	bool m_exitGame;
};
#endif