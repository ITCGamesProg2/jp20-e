#pragma once

#include "SFML/Graphics.hpp"
#include <functional>

class Button
{
public:

	Button();

	void setPosition(const sf::Vector2f t_pos);
	void setString(std::string t_string);
	void centre();
	void uncentre();

	const sf::Vector2f getPosition() const;
	const sf::Vector2f getSize() const;

	bool processInput(/*Xbox360Controller const& t_controller*/);
	void getFocus();
	void looseFocus();
	void update();

	void setCallback(std::function<void()> t_callback);

private:

	sf::Text m_text;
	sf::RectangleShape m_background;

	std::function<void()> m_callback;

	bool m_hasFocus;
};

