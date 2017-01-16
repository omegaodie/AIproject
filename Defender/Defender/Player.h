#pragma once
#ifndef __PLAYER_H__
#define ___PLAYER_H__

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>

#include "GameData.h"

class Player
{
public:
	Player::Player(const GameData& gdata);
	Player::~Player();

	void Init(int lvel);


	void Update();
	void getInput(sf::Event &eve);
	void Draw(sf::RenderWindow &w);

	sf::Vector2f& getPlayerPosition();

private:

	sf::Vector2f displacement;

	float p_rotation;
	

	const GameData& gd;

	sf::Sprite* shipSprite;
	sf::Vector2f shipPos;

	int playerHealth;
	int playerScore;
	sf::Vector2f shipSpeed;
	float dx, dy, px, py, dlength;
};

#endif