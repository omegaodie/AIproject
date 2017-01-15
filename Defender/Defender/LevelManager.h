#pragma once
#ifndef __LEVEL_MANAGER_H__
#define __LEVEL_MANAGER_H__

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "Level.h"
#include "GameData.h"
#include "Player.h"

class LevelManager {

public:

	LevelManager(const GameData& gata, sf::View& view);
	void Initialise();

	void Initialise(int LevelNum);

	void Update();

	void getInput(sf::Event &eve);

	void Draw(sf::RenderWindow &w);

	Level* getCurrentLevel();
	void setCurrentLevel(Level* l);

private:
	const GameData& gd;
	sf::View& view;

	Player thePlayer;

	int currentlevelNum;

	Level* current;

	vector<Level> lm_Levels;
};
#endif

