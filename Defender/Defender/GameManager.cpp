#pragma once
#include"GameManager.h"

GameManager::GameManager() {
	
}


void GameManager::Init( sf::View &v) {
	gameDataSingle = GameData();
	gameState = MENU_RUNNING;
	theMenu = new Menu(gameDataSingle);
	theLevelManager = new LevelManager(gameDataSingle, v);
	theMenu->Init();
	theLevelManager->Initialise(0);
}

GameManager::~GameManager()
{
}



void GameManager::Run(sf::RenderWindow &window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (gameState) {
			case MENU_RUNNING:
			{
				switch (event.type)
				{

					// window closed
				case sf::Event::Closed:
					window.close();
					break;

					// key pressed
				case sf::Event::KeyPressed:
					//...
					break;

				case sf::Event::MouseButtonPressed:
					theMenu->Update(event);

					//...
					break;

					// we don't process other types of events
				default:
					break;
				}

			}
			break;
			case GAME_RUNNING:
			{
				switch (event.type)
				{

					// window closed
				case sf::Event::Closed:
					window.close();
					break;

					// key pressed
				case sf::Event::KeyPressed:
					//...
					theLevelManager->getInput(event);
					break;

				case sf::Event::MouseButtonPressed:
					

					//...
					break;

					// we don't process other types of events
				default:
					break;
				}
			}
			break;
		}
	}

	switch (gameState) {
		case MENU_RUNNING:
			{
				theMenu->Draw(window);
				gameState = theMenu->getState();
			}
			break;
			case GAME_RUNNING:
			{
				theLevelManager->Draw(window);
				theLevelManager->Update();
				//to do
			}
			break;
			case END:
			{
				window.close();
				// End state
			}
			break;
		}
}