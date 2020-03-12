#include "Buttons.h"

/////////////////////////////////////////////////////////////////////////////
Button::Button()
{
	m_text.setString("New Button");
	m_text.setFillColor(sf::Color::Black);

	m_background.setSize({ 250.0f, 80.0f });
}

/////////////////////////////////////////////////////////////////////////////
void Button::setPosition(const sf::Vector2f t_pos)
{
	m_background.setPosition(t_pos);
	m_text.setPosition(m_background.getPosition());
}

/////////////////////////////////////////////////////////////////////////////
void Button::setString(std::string t_string)
{
	m_text.setString(t_string);
}

/////////////////////////////////////////////////////////////////////////////
void Button::centre()
{
	m_background.setOrigin(m_background.getGlobalBounds().width / 2.0f, m_background.getGlobalBounds().height / 2.0f);

}

/////////////////////////////////////////////////////////////////////////////
void Button::uncentre()
{
	m_background.setOrigin(0.0f, 0.0f);
}

/////////////////////////////////////////////////////////////////////////////
const sf::Vector2f Button::getPosition() const
{
	return m_background.getPosition();
}

/////////////////////////////////////////////////////////////////////////////
const sf::Vector2f Button::getSize() const
{
	return { m_background.getGlobalBounds().width, m_background.getGlobalBounds().height };
}

/////////////////////////////////////////////////////////////////////////////
bool Button::processInput(/*Xbox360Controller const& t_controller*/)
{
	bool clicked = false;

	if (m_hasFocus)
	{
		/*if (t_controller.m_currentState.A && !t_controller.m_previousState.A)
		{
			m_background.setFillColor(sf::Color::Red);

			if (nullptr != m_callback)
			{
				m_callback();
				clicked = true;
			}
		}
		else
		{
			m_background.setFillColor(sf::Color::Blue);
		}*/
	}

	return clicked;
}

/////////////////////////////////////////////////////////////////////////////
void Button::getFocus()
{
	m_hasFocus = true;
	m_background.setFillColor(sf::Color::Blue);
}

/////////////////////////////////////////////////////////////////////////////
void Button::looseFocus()
{
	m_hasFocus = false;
	m_background.setFillColor(sf::Color::White);
}

/////////////////////////////////////////////////////////////////////////////
void Button::update()
{
}

/////////////////////////////////////////////////////////////////////////////
void Button::setCallback(std::function<void()> t_callback)
{
	m_callback = t_callback;
}

/////////////////////////////////////////////////////////////////////////////