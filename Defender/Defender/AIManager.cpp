#include "AIManager.h"

AIManager::AIManager(const GameData & gdata, Player& p) : gd(gdata), a_P(p)
{	
	for (int i = 0; i < 3; i++) {
		am_Flocks.push_back(Flock());
	}
	for (int i = 0; i < 5; i++) {
		am_SwarM.push_back(Flock());
	}
}

void AIManager::init(int Ln)
{
	levelNum = Ln;
	am_numUnits = new aiUnits(gd.l_numAiUnits[Ln]);
	am_numUnits->c_abductors = 0;
	am_numUnits->c_astronauts = 0;
	am_numUnits->c_mutants = 0;
	am_numUnits->c_nests = 0;
	sf::Vector2f* p = new sf::Vector2f();

	for (int i = 0; i < am_numUnits->astronauts; i++) {

		am_Astro.push_back(AI(gd));
		am_Astro[i].init(sf::Vector2f((gd.w_Dimensions.x / am_numUnits->astronauts) * i, 800),Ln, 0);
		am_Astro[i].setPattern(2);
		am_numUnits->c_astronauts++;
	}


	for (int i = 0; i < am_numUnits->nests; i++) {
		p->x += p->x * i;
		am_Nests.push_back(AI(gd));
		am_Nests[i].init(sf::Vector2f((gd.w_Dimensions.x / am_numUnits->nests) * i, 128), Ln, 1);
		am_Nests[i].setPattern(2);
		am_numUnits->c_nests++;
	}


	for (int i = 0; i < am_numUnits->abductors; i++) {
		am_Abductors.push_back(AI(gd));
		am_Abductors[i].setPattern(3);
	}
	for (int i = 0; i < am_numUnits->mutants; i++) {
		am_Mutants.push_back(AI(gd));
		am_Mutants[i].init(Ln, 3);
		am_Mutants[i].setPattern(4);
		am_numUnits->c_mutants++;
	}
	FlockingAlgorithim();
}

void AIManager::Update()
{
	Spawn();
	
	for (int i = 0; i < 3; i++) {
		am_Flocks[i].flocking();
	}
	for (int i = 0; i < 5; i++) {
		am_SwarM[i].swarming();
	}
	//Seek();
	//Wander();
	//Swarm();
	//Flee();
	for (int i = 0; i < am_numUnits->astronauts; i++) {
		if (am_Astro[i].getAlive())
		am_Astro[i].Update();
	}
	for (int i = 0; i < am_numUnits->nests; i++) {
		if (am_Nests[i].getAlive())
		am_Nests[i].Update();
	}
	for (int i = 0; i < am_numUnits->c_abductors; i++) {
		if (am_Abductors[i].getAlive()) {
			am_Abductors[i].Update();
		}
		
	}
	for (int i = 0; i < am_numUnits->c_mutants; i++) {
		if (am_Mutants[i].getAlive()) {
			am_Mutants[i].Update();
		}
	}
}

void AIManager::Draw(sf::RenderWindow & w)
{
	for (int i = 0; i < am_numUnits->astronauts; i++) {
		if(am_Astro[i].getAlive())
		am_Astro[i].Draw(w);
	}
	for (int i = 0; i < am_numUnits->nests; i++) {
		if (am_Nests[i].getAlive())
		am_Nests[i].Draw(w);
	}
	for (int i = 0; i < am_numUnits->abductors; i++) {
		if (am_Abductors[i].getAlive())
		am_Abductors[i].Draw(w);
	}
	for (int i = 0; i < am_numUnits->mutants; i++) {
		if (am_Mutants[i].getAlive())
		am_Mutants[i].Draw(w);
	}
}

void AIManager::Spawn() {
	for (int i = 0; i < am_numUnits->nests; i++) {
		if (am_Nests[i].getAbductors() < 20) {
			if (am_Nests[i].makeAbductor()) {
				am_Abductors[am_numUnits->c_abductors].Abductorinit(am_Nests[i].getPosition(), am_Nests[i].getDirection().x, levelNum);
				am_SwarM[i].addBoid(am_Abductors[am_numUnits->c_abductors].getBoid());
				am_numUnits->c_abductors++;
			}
		}
	}
}


void AIManager::Wander()
{
	std::random_device rd;
	
	std::uniform_int_distribution<int> distributionOneX(-1, 1);

	for (int i = 0; i < am_numUnits->c_astronauts; i++) {
		if (am_Astro[i].getPattern() == 2) {
			std::mt19937 mt(rd());
			int x1 = distributionOneX(mt);
			am_Astro[i].setDirection(sf::Vector2f(x1, 0));
		}
	}

	for (int i = 0; i < am_numUnits->c_nests; i++) {
		if (am_Nests[i].getPattern() == 2) {
			std::mt19937 mt(rd());
			int x1 = distributionOneX(mt);
			am_Nests[i].setDirection(sf::Vector2f(x1, 0));
		}
	}

	for (int i = 0; i < am_numUnits->c_abductors; i++) {
		if (am_Abductors[i].getPattern() == 2) {
			std::mt19937 mt(rd());
			int x1 = distributionOneX(mt);
			am_Abductors[i].setDirection(sf::Vector2f(x1, 0));
		}
	}

	for (int i = 0; i < am_numUnits->c_mutants; i++) {
		if (am_Mutants[i].getPattern() == 2) {
			std::mt19937 mt(rd());
			int x1 = distributionOneX(mt);
			am_Mutants[i].setDirection(sf::Vector2f(x1, 0));
		}
	}
}

void AIManager::Swarm()
{

}

void AIManager::Flee()
{

}

void AIManager::AttackPlayer()
{
	sf::Vector2f lineoffire;
	for (int i = 0; i < am_numUnits->abductors; i++) {
		if (am_Abductors[i].getAlive()) {
			if (a_P.getPlayerPosition().x > am_Abductors[i].getPosition().x - 800 && a_P.getPlayerPosition().x < am_Abductors[i].getPosition().x + 800) {
				 lineoffire = sf::Vector2f((a_P.getPlayerPosition().x -
					am_Abductors[i].getPosition().x), (a_P.getPlayerPosition().y - am_Abductors[i].getPosition().y));
				am_Abductors[i].fire(lineoffire);
			}
		}
	}
	for (int i = 0; i < am_numUnits->mutants; i++) {
		if (am_Mutants[i].getAlive())
			if (a_P.getPlayerPosition().x > am_Mutants[i].getPosition().x - 800 && a_P.getPlayerPosition().x < am_Mutants[i].getPosition().x + 800) {
				 lineoffire = sf::Vector2f((a_P.getPlayerPosition().x -
					am_Mutants[i].getPosition().x), (a_P.getPlayerPosition().y - am_Mutants[i].getPosition().y));
				am_Mutants[i].fire(lineoffire);
			}
	}

}

void AIManager::FlockingAlgorithim()
{
	for (int i = 0; i < 10; i++) {
		am_Flocks[0].addBoid(am_Astro[i].getBoid());
	}
	for (int i = 10; i < 20; i++) {
		am_Flocks[1].addBoid(am_Astro[i].getBoid());
	}
	for (int i = 20; i < 30; i++) {
		am_Flocks[2].addBoid(am_Astro[i].getBoid());
	}
}

void AIManager::Seek()
{

}


AI& AIManager::getAstroNauts(int r) {
	return am_Astro[r];
}

AI& AIManager::getNests(int r) {
	return am_Nests[r];
}

AI& AIManager::getAbductors(int r) {
	return am_Abductors[r];
}

AI& AIManager::getMutants(int r) {
	return am_Mutants[r];
}