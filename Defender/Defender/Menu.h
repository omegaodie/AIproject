#ifndef __MENU_H__
#define ___MENU_H__

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameData.h"


class Menu
{
public:

	Menu(const GameData& gamd);
	~Menu();

	void Init();
	int getState();
	
	void Update(sf::Event &eve);
	void Draw(sf::RenderWindow &w);

private:

	void DrawButtons(sf::RenderWindow &w);
	void DrawBackground(sf::RenderWindow &w);

	std::vector<Button> m_Btns;

	sf::Sprite m_backGroundSprite;

	bool exit, play;

	float x;

	const GameData& gd;
};

#endif 