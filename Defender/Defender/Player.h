#pragma once
#ifndef __PLAYER_H__
#define ___PLAYER_H__

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>
#include "Bullet.h"
#include "GameData.h"

class Player
{
public:
	Player::Player(const GameData& gdata);
	Player::~Player();

	void Init(int lvel);

	void isHit();

	void Update();
	void getInput(sf::Event &eve);
	void Draw(sf::RenderWindow &w);

	sf::Vector2f& getPlayerPosition();
	Bullet& getBullet(int i);

	vector<int> getBulletsFired();

private:


	void fire();

	sf::Vector2f displacement;
	
	int hp;

	vector<int> p_BulletsFire;

	float p_rotation;
	
	bool movingLeft, turning, alive;

	const GameData& gd;

	sf::Sprite* shipSprite;
	sf::Vector2f shipPos;

	vector<Bullet> p_Bullets;

	int playerHealth;
	int playerScore;
	sf::Vector2f shipSpeed;
	float dx, dy, px, py, dlength;
};

#endif