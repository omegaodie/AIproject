#pragma once
#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "AIManager.h"
#include "GameData.h"
#include "Player.h"

class Level {

public:

	Level(const GameData& gdata, Player& p, sf::View& view);

	void init(int levelNum);

	bool Update();

	void getInput(sf::Event &eve);

	void Draw(sf::RenderWindow &w);

private:

	void moveWorld(sf::Vector2f& ps); // we move the world according to the speed of the player

	sf::View& view;

	Player& l_Player;

	int l_Num;

	const GameData& gd;

	sf::Sprite* l_worldSprite; // the scrolling background 
	sf::Vector2f l_worldSpritePos; //where we are at
	AIManager l_AIM; // controlls all enemey units



};
#endif
