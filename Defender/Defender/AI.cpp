#include "AI.h"


AI::AI(const GameData& gdata) : gd(gdata) {
	e_Sprite = sf::Sprite();
	e_Pos = sf::Vector2f();
	e_direction = sf::Vector2f();
	e_alive = false;
}

void AI::init(int ln, int t)
{
	e_Pos.x = t * 100;
	e_Pos.y = 40;
	e_type = t;
	if (e_type == ASTRONAUT) {
		e_Sprite.setTexture(gd.ai_astronautTexture);
		e_randTimer = 120;

		e_Sprite.setPosition(e_Pos);
		e_direction.x = 1;
		e_direction.y = 0;
	}
	else if (e_type == NEST)
	{
		e_Sprite.setTexture(gd.ai_nestTexture);
		e_randTimer = 120;

		e_Sprite.setPosition(e_Pos);
		e_direction.x = 1;
		e_direction.y = 0;
	}
	else if (e_type == ABDUCTOR)
	{
		e_Sprite.setTexture(gd.ai_abductorTexture);
	}
	else { //MUTANT
		   //e_Sprite.setTexture(gd.ai_);
	}



}

void AI::Abductorinit(sf::Vector2f& spwn, int dir, int ln) {
	e_Pos.x = spwn.x;
	e_Pos.y = spwn.y;
	e_type = 2;
	e_direction.x = -dir;
	e_Sprite.setTexture(gd.ai_abductorTexture);
	e_randTimer = 64;
	e_Sprite.setPosition(e_Pos);
	e_alive = true;
}



bool AI::getWander() {
	return a_wander;
}

void AI::setWander(bool b) {
	a_wander = b;
}


void AI::init(sf::Vector2f p, int ln, int t)
{
	e_Pos = p;
	e_type = t;
	if (e_type == ASTRONAUT) {
		e_Sprite.setTexture(gd.ai_astronautTexture);
		e_randTimer = 0;
		e_Sprite.setPosition(e_Pos);
		e_Sprite.setOrigin(gd.ai_astronautDimensions.x / 2, gd.ai_astronautDimensions.y / 2);
		e_direction.x = 0;
		e_direction.y = 0;
		e_alive = true;
	}
	else if (e_type == NEST)
	{
		e_Sprite.setPosition(e_Pos);
		n_SpawnAbductorTimer = 0;
		e_direction.x = 0;
		e_direction.y = 0;
		e_alive = true;
		n_numAbductors = 0;
		e_Sprite.setTexture(gd.ai_nestTexture);
		e_Sprite.setOrigin(gd.ai_nestDimensions.x / 2, gd.ai_nestDimensions.y / 2);
		e_randTimer = 512;
		e_Sprite.setRotation(90);
	}
	else if (e_type == ABDUCTOR)
	{
		e_Sprite.setTexture(gd.ai_abductorTexture);
		e_randTimer = 64;
		e_Sprite.setPosition(e_Pos);
		e_Sprite.setOrigin(gd.ai_abductorDimensions.x / 2, gd.ai_abductorDimensions.y / 2);
		e_alive = true;
	}
	else { //MUTANT
		//e_Sprite.setTexture(gd.ai_);
	}

	e_randTimer = 120;
	
	e_Sprite.setPosition(e_Pos);
	e_direction.x = 1;
	e_direction.y = 0;


}


float AI::getTimer() {
	return e_randTimer;
}

void AI::Update()
{
	e_Pos.x += e_direction.x;
	e_Pos.y += e_direction.y;
	
	if (e_type == ASTRONAUT) {
		e_randTimer ++;
		e_Sprite.setPosition(e_Pos);
	}
	else if (e_type == NEST)
	{
		n_SpawnAbductorTimer++;
		e_Sprite.setPosition(e_Pos);
	}
	else if (e_type == ABDUCTOR)
	{
		e_Sprite.setPosition(e_Pos);
	}
	else { //MUTANT
		e_Sprite.setPosition(e_Pos);
	}

}


bool AI::getAlive() {
	return e_alive;
}

int AI::getAbductors()
{
	return n_numAbductors;
}

void AI::makeAbductor()
{
	if (n_SpawnAbductorTimer >= 128) {
		n_numAbductors++;
		n_SpawnAbductorTimer = 0;
	}
}


sf::Vector2f& AI::getDirection() {
	return e_direction;
}

void AI::setDirection(sf::Vector2f & d)
{
	if (e_type == ASTRONAUT) {
		if (e_randTimer >= 128) {
			e_direction = d;
			e_randTimer = 0;
			if (e_direction.x > 0) {
				e_Sprite.setScale(1.f, 1.f);
			}
			else {
				e_Sprite.setScale(-1.f, 1.f);
			}
		}
	}
	else if (e_type == NEST)
	{
		if (e_randTimer >= 512) {
			e_direction = d;
			e_randTimer = 0;
			if (e_direction.x > 0) {
				e_Sprite.setRotation(90);
			}
			else {
				e_Sprite.setRotation(-90);
			}
		}
		
	}
	else if (e_type == ABDUCTOR)
	{

	}
	else { //MUTANT
		   //e_Sprite.setTexture(gd.ai_);
	}

}

void AI::Draw(sf::RenderWindow &w)
{
	w.draw(e_Sprite);
}


sf::Vector2f AI::getPosition() {
	return e_Pos;
}

int AI::getPattern() {
	return e_pattern;
}

void AI::setPattern(int p) {
	e_pattern = p;
}
