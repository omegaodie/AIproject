#include "AIManager.h"

AIManager::AIManager(const GameData & gdata) : gd(gdata)
{

}

void AIManager::init(int Ln)
{
	am_numUnits = new aiUnits(gd.l_numAiUnits[Ln]);

	for (int i = 0; i < am_numUnits->astronauts; i++) {
		am_Astro.push_back(AI(gd));
		am_Astro[i].init(Ln, 0);
		am_Astro[i].setPattern(2);
	}
	for (int i = 0; i < am_numUnits->nests; i++) {
		am_Nests.push_back(AI(gd));
		am_Nests[i].init(Ln, 1);
		am_Nests[i].setPattern(2);
	}
	for (int i = 0; i < am_numUnits->abductors; i++) {
		am_Abductors.push_back(AI(gd));
		am_Abductors[i].init(Ln, 2);
		am_Abductors[i].setPattern(3);
	}
	for (int i = 0; i < am_numUnits->mutants; i++) {
		am_Mutants.push_back(AI(gd));
		am_Mutants[i].init(Ln, 3);
		am_Mutants[i].setPattern(4);
	}
}

void AIManager::Update()
{
	Flock();
	Seek();
	Wander();
	Swarm();
	Flee();
	for (int i = 0; i < am_numUnits->astronauts; i++) {
		am_Astro[i].Update();
	}
	for (int i = 0; i < am_numUnits->nests; i++) {
		am_Nests[i].Update();
	}
	for (int i = 0; i < am_numUnits->abductors; i++) {
		am_Abductors[i].Update();
	}
	for (int i = 0; i < am_numUnits->mutants; i++) {
		am_Mutants[i].Update();
	}
}

void AIManager::Draw(sf::RenderWindow & w)
{
	for (int i = 0; i < am_numUnits->astronauts; i++) {
		am_Astro[i].Draw(w);
	}
	for (int i = 0; i < am_numUnits->nests; i++) {
		am_Nests[i].Draw(w);
	}
	for (int i = 0; i < am_numUnits->abductors; i++) {
		am_Abductors[i].Draw(w);
	}
	for (int i = 0; i < am_numUnits->mutants; i++) {
		am_Mutants[i].Draw(w);
	}
}




void AIManager::Wander()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distributionOneX(-1, 1);
	sf::Vector2f astrodirectionVec = sf::Vector2f(0,40);
	for (int i = 0; i < am_numUnits->astronauts; i++) {
		int x1 = distributionOneX(mt);
		if ((am_Astro[i].getPattern() == 2)&&(am_Astro[i].getTimer() <= 0)) {
			astrodirectionVec.x = x1 * 5;
			am_Astro[i].setDirection(astrodirectionVec);
		}
	}



	//  wanderOrientation += random(-1, +1) * wanderRate
	//	targetOrientation = wanderOrientation + my.orientation
	//	target = my.position + wanderOffset * my.orientation.asVector()
	//	target += wanderRadius * targetOrientation.asVector()
	//	face(target)
	//	linAcc = maxAcc * my.orientation.asVector()
}

void AIManager::Swarm()
{

}

void AIManager::Flee()
{

}

void AIManager::Flock()
{

}

void AIManager::Seek()
{

}
