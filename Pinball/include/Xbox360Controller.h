// @Author: Ben Millar – C00236772
// @Date: 19/09/2019
// @brief: A class to act as an interface between an Xbox 360 controller and a simple game
// utilising the SFML joystick class. Handles queries as to the state of the controller input.
// Estimated time to complete: 4 hours
// Session 1 Start: 13:20 End: 14:10
// Session 2 Start: 12:20 End: 14:00
// Session 3 Start: 10:30 End: 11:30
// Session 4 Start: 11:45 End: 11:55
// Session 5 Start: 15:10 End: 16:10
// Session 6 Start: 15:10 End: 15:30
// Session 7 Start: 15:00 end: 16:20
// Total time: 6:20

#ifndef XBOX360CONTROLLER_H
#define XBOX360CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>

/// <summary>
/// Stores the current state of the controller
/// </summary>
struct GamePadState
{
	bool A{ false };
	bool B{ false };
	bool X{ false };
	bool Y{ false };
	bool LB{ false };
	bool RB{ false };
	bool LeftThumbStickClick{ false };
	bool RightThumbStickClick{ false };
	bool DpadUp{ false };
	bool DpadDown{ false };
	bool DpadLeft{ false };
	bool DpadRight{ false };
	bool Start{ false };
	bool Back{ false };
	bool Xbox{ false };
	float LTrigger{ 0.0f };
	float RTrigger{ 0.0f };
	sf::Vector2f LeftThumbStick{ 0.0f,0.0f };
	sf::Vector2f RightThumbStick{ 0.0f,0.0f };
};

/// <summary>
/// Used as an interface to query the controller state
/// </summary>
class Xbox360Controller
{
public:

	// *** Methods ***

	Xbox360Controller();
	~Xbox360Controller();

	void update();
	bool isConnected();
	bool connect();

	// *** Variables ***

	// number of controllers connected
	static int s_noOfControllers;
	// index count for multiple controllers - hard coded at the minute
	int sf_Joystick_index{ 0 };
	// the current state for all buttons
	GamePadState m_currentState;
	// the previous state for all buttons
	GamePadState m_previousState;

private:
	// deadzone for the dpad
	const int dPadThreshold = 40;
	// deadzone for the thumbstick
	const float m_thumbStickThreshold = 15.0f;
};

#endif