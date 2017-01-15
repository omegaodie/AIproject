#include "LevelManager.h"

LevelManager::LevelManager(const GameData & gdata,  sf::View& v) :  gd(gdata), view(v), thePlayer(Player(gdata))
{
}

void LevelManager::Initialise()
{
	for (int i = 0; i < gd.numLevels; i++) {
		lm_Levels.push_back(Level(gd, thePlayer, view));
	}
}

void LevelManager::Initialise(int LevelNum)
{
	currentlevelNum = LevelNum;
	for (int i = 0; i < gd.numLevels; i++) {
		lm_Levels.push_back(Level(gd, thePlayer, view));
	}
	current = new Level(lm_Levels[currentlevelNum]);
	current->init(LevelNum);
}

void LevelManager::Update()
{
	current->Update();
}

void LevelManager::getInput(sf::Event & eve)
{
	current->getInput(eve);
}

void LevelManager::Draw(sf::RenderWindow &w)
{
	current->Draw(w);
}

Level * LevelManager::getCurrentLevel()
{
	return current;
}

 void LevelManager::setCurrentLevel(Level * l)
{
	 current = l;
}
