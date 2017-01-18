#pragma once
#ifndef __COLLISION_MANAGER_H__
#define __COLLISION_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>
#include "GameData.h"

class CollisionManager
{
public:
	CollisionManager(const GameData& gdata);

	~CollisionManager();

	bool getcollision( sf::IntRect& aR, sf::IntRect& bR );

	bool TestWallCollision(sf::IntRect r);	// CollisionManager against the training room walls

private:
	const GameData& gd;
};

#endif