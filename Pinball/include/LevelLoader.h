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

struct LevelData
{
	BackgroundData m_background;
	BallData m_ball;
	std::vector<ObstacleData> m_obstacles;
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

