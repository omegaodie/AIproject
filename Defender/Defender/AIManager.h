#pragma once
#ifndef __AI_MANAGER_H__
#define __AI_MANAGER_H__

#include <SFML/Graphics.hpp>
#include "GameData.h"
#include <random>
#include "AI.h"

class AIManager {

public:

	AIManager(const GameData& gd);

	void init(int Ln);

	void Update();

	void Draw(sf::RenderWindow &w);

	void Flock();

	void Seek();

	void Wander();

	void Swarm();

	void Flee();

	void Spawn();

private:
	const GameData& gd;
	
	aiUnits* am_numUnits;

	int levelNum;

	vector<AI> am_Astro;
	vector<AI> am_Nests;
	vector<AI> am_Abductors;
	vector<AI> am_Mutants;



};
#endif
