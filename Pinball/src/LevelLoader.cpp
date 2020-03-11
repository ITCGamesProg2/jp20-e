#include "LevelLoader.h"


void operator >> (const YAML::Node& obstacleNode, ObstacleData& obstacle)
{
	obstacle.m_type = obstacleNode["type"].as<std::string>();
	obstacle.m_position.x = obstacleNode["position"]["x"].as<float>();
	obstacle.m_position.y = obstacleNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& barrierNode, BarrierData& barrier)
{
	barrier.m_position1.x = barrierNode["start"]["x"].as<float>();
	barrier.m_position1.y = barrierNode["start"]["y"].as<float>();
	barrier.m_position2.x = barrierNode["end"]["x"].as<float>();
	barrier.m_position2.y = barrierNode["end"]["y"].as<float>();
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

void operator >> (const YAML::Node& leftFlipperNode, LeftFlipperData& flipper)
{
	flipper.m_position.x = leftFlipperNode["position"]["x"].as<float>();
	flipper.m_position.y = leftFlipperNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& rightFlipperNode, RightFlipperData& flipper)
{
	flipper.m_position.x = rightFlipperNode["position"]["x"].as<float>();
	flipper.m_position.y = rightFlipperNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& springNode, SpringData& spring)
{
	spring.m_position.x = springNode["position"]["x"].as<float>();
	spring.m_position.y = springNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["background"] >> level.m_background;

	levelNode["ball"] >> level.m_ball;

	levelNode["leftFlipper"] >> level.m_leftFlipper;

	levelNode["rightFlipper"] >> level.m_rightFlipper;

	levelNode["spring"] >> level.m_spring;

	const YAML::Node& obstaclesNode = levelNode["obstacles"].as<YAML::Node>();
	{
		for (unsigned i = 0; i < obstaclesNode.size(); i++)
		{
			ObstacleData obstacle;
			obstaclesNode[i] >> obstacle;
			level.m_obstacles.push_back(obstacle);
		}
	}

	const YAML::Node& barrierNode = levelNode["barriers"].as<YAML::Node>();
	{
		for (unsigned i = 0; i < barrierNode.size(); i++)
		{
			BarrierData barrier;
			barrierNode[i] >> barrier;
			level.m_barriers.push_back(barrier);
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
		if (baseNode.IsNull())
		{
			std::string message("File: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
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
