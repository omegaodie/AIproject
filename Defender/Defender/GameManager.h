#pragma once
// a manager of managers#ifndef __GAME_H__
#ifndef ___GAMEM_MANAGER_H__
#define ___GAMEM_MANAGER_H__


#include <SFML/Graphics.hpp>
#include <vector>
#include "AIManager.h"
#include "Renderer.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>
#include "Menu.h"
#include "LevelManager.h"


class GameManager
{
public:
	GameManager();
	GameManager::~GameManager();
	void GameManager::Init(sf::View &v);

	void GameManager::Run(sf::RenderWindow &w);
	sf::Clock* clock;

private:

	GameData gameDataSingle;
	int gameState;
	Menu* theMenu;
	LevelManager* theLevelManager;
	enum GameState { MENU_RUNNING = 0, GAME_RUNNING = 1, END = 2 };
};

#endif 