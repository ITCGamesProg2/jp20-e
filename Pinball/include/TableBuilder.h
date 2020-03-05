#pragma once
#include "BaseScreen.h"

class TableBuilder :
	public BaseScreen
{
public:

	TableBuilder(sf::Font& t_font);
	~TableBuilder() = default;

	/// <summary>
	/// @brief Handles SFML events (keypress, mouseclick, etc.)
	/// </summary>
	/// <param name="t_event">sf::Event object to process</param>
	void processEvents(sf::Event t_events) override;

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

	sf::Font& m_font;

	sf::Text m_text;
};

