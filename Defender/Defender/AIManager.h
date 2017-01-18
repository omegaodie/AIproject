#pragma once
#ifndef __AI_MANAGER_H__
#define __AI_MANAGER_H__

#include <SFML/Graphics.hpp>
#include "GameData.h"
#include <random>
#include "AI.h"
#include "Player.h"
#include "Flock.h"

class AIManager {

public:

	AIManager(const GameData& gd, Player& p);

	void init(int Ln);

	void Update();

	void Draw(sf::RenderWindow &w);

	void FlockingAlgorithim();

	void Seek();

	void Wander();

	void Swarm();

	void Flee();

	void AttackPlayer();


	AI& getAstroNauts(int r);

	AI& getNests(int r);

	AI& getAbductors(int r);

	AI& getMutants(int r);


	void Spawn();

private:
	const GameData& gd;

	Player& a_P;
	
	aiUnits* am_numUnits;

	int levelNum;

	vector<AI> am_Astro;
	vector<AI> am_Nests;
	vector<AI> am_Abductors;
	vector<AI> am_Mutants;

	vector<Flock> am_Flocks;
	vector<Flock> am_SwarM;

};
#endif
