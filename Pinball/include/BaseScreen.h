#pragma once

#include <SFML/Graphics.hpp>

class BaseScreen
{
public:

	BaseScreen() = default;
	virtual ~BaseScreen() {}

protected:

	virtual void update(sf::Time t_dTime) = 0;
	virtual void render(sf::RenderWindow& t_window) = 0;
};