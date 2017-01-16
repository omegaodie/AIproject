#pragma once
#ifndef __AI_H__
#define __AI_H__

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "GameData.h"

class AI {

public:

	AI(const GameData& gd);

	virtual void init(int ln, int type);

	virtual void init(sf::Vector2f* spwn, int ln, int type);

	sf::Vector2f getPosition();

	int getPattern();

	void setPattern(int p);

	void Update();

	float getTimer();

	void setDirection(sf::Vector2f& d);

	void Draw(sf::RenderWindow &w);


private:

	int e_pattern, e_type;

	float timer;

	sf::Sprite e_Sprite;

	sf::Vector2f e_Pos;

	sf::Vector2f e_direction;

	enum Pattern { SWARM = 0, FLEE = 1, WANDER = 2, FLOCK = 3, SEEK = 4 };

	enum AIType { ASTRONAUT = 0, NEST = 1, ABDUCTOR = 2, MUTANT = 3};

	const GameData& gd;

};
#endif
