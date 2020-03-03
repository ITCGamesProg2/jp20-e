#include "Xbox360Controller.h"

/// <summary>
/// Default constructor
/// </summary>
Xbox360Controller::Xbox360Controller()
{
}

/// <summary>
/// Default destructor
/// </summary>
Xbox360Controller::~Xbox360Controller()
{
}

void Xbox360Controller::update()
{
	sf::Joystick::update();

	m_previousState.A = m_currentState.A;
	m_previousState.B = m_currentState.B;
	m_previousState.X = m_currentState.X;
	m_previousState.Y = m_currentState.Y;
	m_previousState.LB = m_currentState.LB;
	m_previousState.RB = m_currentState.RB;
	m_previousState.LeftThumbStickClick = m_currentState.LeftThumbStickClick;
	m_previousState.RightThumbStickClick = m_currentState.RightThumbStickClick;
	m_previousState.DpadUp = m_currentState.DpadUp;
	m_previousState.DpadDown = m_currentState.DpadDown;
	m_previousState.DpadLeft = m_currentState.DpadLeft;
	m_previousState.DpadRight = m_currentState.DpadRight;
	m_previousState.Start = m_currentState.Start;
	m_previousState.Back = m_currentState.Back;
	m_previousState.Xbox = m_currentState.Xbox;
	m_previousState.LTrigger = m_currentState.LTrigger;
	m_previousState.RTrigger = m_currentState.RTrigger;
	m_previousState.LeftThumbStick = m_currentState.LeftThumbStick;
	m_previousState.RightThumbStick = m_currentState.RightThumbStick;

	// ++++++++++ A/B/X/Y ++++++++++

	m_currentState.A = sf::Joystick::isButtonPressed(sf_Joystick_index, 0);
	m_currentState.B = sf::Joystick::isButtonPressed(sf_Joystick_index, 1);
	m_currentState.X = sf::Joystick::isButtonPressed(sf_Joystick_index, 2);
	m_currentState.Y = sf::Joystick::isButtonPressed(sf_Joystick_index, 3);

	// ++++++++++ Bumpers ++++++++++

	m_currentState.LB = sf::Joystick::isButtonPressed(sf_Joystick_index, 4);
	m_currentState.RB = sf::Joystick::isButtonPressed(sf_Joystick_index, 5);

	// ++++++++++ Triggers ++++++++++

	m_currentState.LTrigger = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Z);
	m_currentState.RTrigger = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Z);

	// ++++++++++ Analogue Sticks ++++++++++

	m_currentState.LeftThumbStickClick = sf::Joystick::isButtonPressed(sf_Joystick_index, 8);
	m_currentState.RightThumbStickClick = sf::Joystick::isButtonPressed(sf_Joystick_index, 9);

	m_currentState.LeftThumbStick = { sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::X),
									  sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::Y) };

	// deadzone checking (left thumbstick)
	if (m_currentState.LeftThumbStick.x < m_thumbStickThreshold && m_currentState.LeftThumbStick.x > -(m_thumbStickThreshold))
	{
		m_currentState.LeftThumbStick.x = 0.0f;
	}
	if (m_currentState.LeftThumbStick.y < m_thumbStickThreshold && m_currentState.LeftThumbStick.y > -(m_thumbStickThreshold))
	{
		m_currentState.LeftThumbStick.y = 0.0f;
	}

	m_currentState.RightThumbStick = { sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::U),
									   sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::V) };

	// deadzone checking (right thumbstick)
	if (m_currentState.RightThumbStick.x < m_thumbStickThreshold && m_currentState.RightThumbStick.x > -(m_thumbStickThreshold))
	{
		m_currentState.RightThumbStick.x = 0.0f;
	}
	if (m_currentState.RightThumbStick.y < m_thumbStickThreshold && m_currentState.RightThumbStick.y > -(m_thumbStickThreshold))
	{
		m_currentState.RightThumbStick.y = 0.0f;
	}

	// ++++++++++ D-Pad ++++++++++

	m_currentState.DpadUp = (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovY) > dPadThreshold) ? true : false;
	m_currentState.DpadDown = (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovY) < -(dPadThreshold)) ? true : false;
	m_currentState.DpadLeft = (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovX) < -(dPadThreshold)) ? true : false;
	m_currentState.DpadRight = (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Axis::PovX) > dPadThreshold) ? true : false;

	// ++++++++++ Start/XBOX/Back ++++++++++

	m_currentState.Start = sf::Joystick::isButtonPressed(sf_Joystick_index, 7);
	m_currentState.Back = sf::Joystick::isButtonPressed(sf_Joystick_index, 6);
	m_currentState.Xbox = sf::Joystick::isButtonPressed(sf_Joystick_index, 15);
}

/// <summary>
/// @brief Checks if controller is connected
/// </summary>
/// <returns>True if controller connected, false otherwise</returns>
bool Xbox360Controller::isConnected()
{
	return (sf::Joystick::isConnected(sf_Joystick_index));
}

/// <summary>
/// I'm not sure what this should do :(
/// </summary>
/// <returns>true if connection successful</returns>
bool Xbox360Controller::connect()
{
	if (sf::Joystick::isConnected(sf_Joystick_index))
	{
		std::cout << "connected" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
