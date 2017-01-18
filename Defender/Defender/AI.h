#pragma once
#ifndef __AI_H__
#define __AI_H__

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "GameData.h"
#include "Bullet.h"
#include "Boid.h"

class AI {

public:

	AI(const GameData& gd);

	void init(int ln, int type);

	void init(sf::Vector2f spwn, int ln, int type);

	void Abductorinit(sf::Vector2f& spwn, int dir, int ln);

	sf::Vector2f getPosition();

	int getPattern();

	void setPattern(int p);

	void Update();

	float getTimer();

	void setDirection(sf::Vector2f& d);

	void Draw(sf::RenderWindow &w);

	bool getAlive();

	int getAbductors();

	bool makeAbductor();

	bool getWander();

	void setWander(bool b);

	void setAlive(bool b);

	sf::Vector2f& getDirection();

	Bullet& getBullet(int i);

	void fire(sf::Vector2f dir);

	void Seperation(float s);

	void Alignment(float a);

	Boid& getBoid();


private:

	int e_pattern, e_type;

	int e_range, n_numAbductors;

	float e_randTimer, n_SpawnAbductorTimer;

	int speed;

	bool e_alive, a_wander;

	vector<Bullet> e_Bullets;

	Boid e_Boid;

	vector<int> fireBullets;

	sf::Sprite e_Sprite;

	sf::Vector2f e_Pos;

	sf::Vector2f e_direction;

	enum Pattern { SWARM = 0, FLEE = 1, WANDER = 2, FLOCK = 3, SEEK = 4 };

	enum AIType { ASTRONAUT = 0, NEST = 1, ABDUCTOR = 2, MUTANT = 3};

	const GameData& gd;

};
#endif
