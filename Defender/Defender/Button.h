//not my own work but it's just a button for the menu and doesnt constitute core gameplay surely
// source: http://en.sfml-dev.org/forums/index.php?topic=5950.0
// owner: asdatapel
//i've made it better though, don't like what he did at all really
#pragma once
#ifndef __BUTTON_H__
#define ___BUTTON_H__

#include <SFML/Graphics.hpp>
#include "GameData.h"

class Button {
public:
	Button(const GameData& gamd);
	void Init(sf::Vector2f pos, int name);
	void Init(int name);
	void checkClick(sf::Vector2i);
	void setState(bool b);
	bool getState();
	void Update(sf::Event &eve);
	void Draw(sf::RenderWindow &w);

	string getName();
private:

	sf::Vector2f* b_Pos;
	string b_string;

	sf::Sprite b_sprite;
	const GameData& gd;

	bool current;
};
#endif