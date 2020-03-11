#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <yaml-cpp/yaml.h>

/// <summary>
/// @brief A struct to represent Obstacle data in the level 
/// </summary>
struct ObstacleData
{
	std::string m_type;
	sf::Vector2f m_position;

};

/// <summary>
/// @brief A struct to represent the Ball data in the level 
/// </summary>
struct BallData
{
	sf::Vector2f m_position;
};

/// <summary>
/// @brief A struct to background texture information 
/// </summary>
struct BackgroundData
{
	std::string m_fileName;
};

/// <summary>
/// @brief A struct to represent the Left Flipper data in the level 
/// </summary>
struct LeftFlipperData
{
	sf::Vector2f m_position;
};

/// <summary>
/// @brief A struct to represent the Left Flipper data in the level 
/// </summary>
struct RightFlipperData
{
	sf::Vector2f m_position;
};

/// <summary>
/// @brief a struct to hold the positions of the barrier
/// </summary>
struct BarrierData
{
	sf::Vector2f m_position1;
	sf::Vector2f m_position2;
};

struct SpringData
{
	sf::Vector2f m_position;
};

struct LevelData
{
	BackgroundData m_background;
	BallData m_ball;
	std::vector<ObstacleData> m_obstacles;
	LeftFlipperData m_leftFlipper;
	RightFlipperData m_rightFlipper;
	std::vector<BarrierData> m_barriers;
	SpringData m_spring;
};

class LevelLoader
{
public:
	/// <summary>
	/// @brief Default constructor
	/// </summary>
	LevelLoader() = default;


	static void load(int nr, LevelData& level);

};

