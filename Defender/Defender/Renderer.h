#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class Renderer {

public:

	Renderer();
	void Draw(sf::RenderWindow &w);

private:

};
#endif