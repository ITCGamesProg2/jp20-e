#include "LevelLoader.h"


void operator >> (const YAML::Node& obstacleNode, ObstacleData& obstacle)
{
	obstacle.m_type = obstacleNode["type"].as<std::string>();
	obstacle.m_position.x = obstacleNode["position"]["x"].as<float>();
	obstacle.m_position.y = obstacleNode["position"]["y"].as<float>();
}

void  operator >> (const YAML::Node& backgroundNode, BackgroundData& background)
{
	background.m_fileName = backgroundNode["file"].as<std::string>();
}

void operator >> (const YAML::Node& ballNode, BallData& ball)
{
	ball.m_position.x = ballNode["position"]["x"].as<float>();
	ball.m_position.y = ballNode["position"]["y"].as<float>();
}


void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["background"] >> level.m_background;

	levelNode["ball"] >> level.m_ball;

	const YAML::Node& obstaclesNode = levelNode["obstacles"].as<YAML::Node>();
	{
		for (unsigned i = 0; i < obstaclesNode.size(); i++)
		{
			ObstacleData obstacle;
			obstaclesNode[i] >> obstacle;
			level.m_obstacles.push_back(obstacle);
		}
	}

}


void LevelLoader::load(int nr, LevelData& level)
{
	std::stringstream ss;
	ss << ".\\ASSETS\\LEVELS\\level";
	ss << nr;
	ss << ".yaml";

	std::cout << ss.str() << std::endl;

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		/*if (baseNode.IsNull())
		{
			std::string message("File: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}*/
		//baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::string message(e.what());
		message = "YAML Parser Error: " + message;
		throw std::exception(message.c_str());
	}
	catch (std::exception& e)
	{
		std::string message(e.what());
		message = "Unexpected Error: " + message;
		throw std::exception(message.c_str());
	}
}
