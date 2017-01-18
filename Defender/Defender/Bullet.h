#pragma once
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include <istream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "GameData.h"

#define PI 3.14159265

class Bullet
{
public:
	Bullet::Bullet(const GameData& gdata);
	void init(sf::Vector2f& src, sf::Vector2f& dir, float rot);
	Bullet::~Bullet();

	void setAlive(bool b);

	bool getAlive();

	void reset();

	sf::Vector2f& getPosition();

	void Bullet::Update();		// Update bullet positions, bullet source position, check if off-screen
	void Bullet::Draw(sf::RenderWindow &w);					// Draw bullets
	
private:
	const GameData& gd;

	int timer;

	bool b_alive;

	float b_Speed, b_rotation;

	sf::Sprite b_Sprite;		// The enemy bullet sprite

	sf::Vector2f b_direction;

	sf::Vector2f b_Pos;

};