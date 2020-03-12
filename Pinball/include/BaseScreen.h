#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "ScreenType.h"
#include "Xbox360Controller.h"

class BaseScreen
{
public:

	BaseScreen() = default;
	virtual ~BaseScreen() {}

	virtual void processEvents(sf::Event t_event, Xbox360Controller& t_controller) = 0;
	virtual void update(sf::Time t_dTime, Xbox360Controller& t_controller) = 0;
	virtual void render(sf::RenderWindow& t_window) = 0;
};