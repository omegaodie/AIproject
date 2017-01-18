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
		for (int i = 0; i < 10; i++) {
			e_Bullets.push_back(Bullet(gd));
		}
	}
	else { //MUTANT
		   //e_Sprite.setTexture(gd.ai_);
		for (int i = 0; i < 10; i++) {
			e_Bullets.push_back(Bullet(gd));
		}
	}



}

void AI::Abductorinit(sf::Vector2f& spwn, int dir, int ln) {
	for (int i = 0; i < 10; i++) {
		e_Bullets.push_back(Bullet(gd));
	}
	e_Pos.x = spwn.x;
	e_Pos.y = spwn.y;
	e_type = 2;
	e_direction.x = -dir;
	e_Sprite.setTexture(gd.ai_abductorTexture);
	e_randTimer = 64;
	e_Sprite.setPosition(e_Pos);
	e_Boid = Boid(e_Pos.x, e_Pos.y);
	e_alive = true;
}



bool AI::getWander() {
	return a_wander;
}

void AI::setWander(bool b) {
	a_wander = b;
}

void AI::setAlive(bool b)
{
	e_alive = b;
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
		e_Boid = Boid(e_Pos.x, e_Pos.y, true);
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



	if ((e_Pos.x >= 128) && (e_Pos.x <= gd.w_Dimensions.x - 128)) {
		e_Pos.x += e_direction.x;
	}
	else {
		//stuff
		if (e_Pos.x <= 128) {
			e_Pos.x += 8;
			e_direction.x = 0.5;
		}
		else {
			e_Pos.x -= 8;
			e_direction.x = -0.5;
		}
	}
	if ((e_Pos.y >= 128) && (e_Pos.y <= (gd.w_Dimensions.y / 2) - 128)) {
		e_Pos.y += e_direction.y;
	}
	else {
		//stuff

		if (e_Pos.y <= 128) {
			e_Pos.y += 8;
			e_direction.y = 0.5;
		}
		else {
			e_Pos.y -= 8;
			e_direction.y = -0.5;
		}
	}
	
	if (e_type == ASTRONAUT) {
		e_direction = e_Boid.getDirection();
		e_Pos.x += e_direction.x;
		e_Pos.y += 0;
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
		e_direction = e_Boid.getDirection();
		e_Pos.x += e_direction.x;
		e_Pos.y += e_direction.y;
		e_Sprite.setPosition(e_Pos);
		for (int i = 0; i < 10; i++) {
			if (e_Bullets[i].getAlive() == true) {
				e_Bullets[i].Update();
			}
		}
		for (int i = 0; i < fireBullets.size(); i++) {
			if (e_Bullets[fireBullets[i]].getAlive() == false) {
				e_Bullets[fireBullets[i]].reset();
			}
		}
	}
	else { //MUTANT
		e_Sprite.setPosition(e_Pos);
		e_Sprite.setPosition(e_Pos);
		for (int i = 0; i < 10; i++) {
			if (e_Bullets[i].getAlive() == true) {
				e_Bullets[i].Update();
			}
		}
		for (int i = 0; i < fireBullets.size(); i++) {
			if (e_Bullets[fireBullets[i]].getAlive() == false) {
				e_Bullets[fireBullets[i]].reset();
			}
		}
	}

}

Boid& AI::getBoid() {
	return e_Boid;
}


bool AI::getAlive() {
	return e_alive;
}

int AI::getAbductors()
{
	return n_numAbductors;
}

bool AI::makeAbductor()
{
	if (n_SpawnAbductorTimer >= 250) {
		n_numAbductors++;
		n_SpawnAbductorTimer = 0;
		return true;
	}
	else {
		return false;
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
		e_direction = d;
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

Bullet& AI::getBullet(int r) {
	return e_Bullets[r];
}

void AI::fire(sf::Vector2f dir)
{
	for (int i = 0; i < 10; i++) {
		if (e_Bullets[i].getAlive() != true) {
			e_Bullets[i].init(e_Pos, dir, 0);
			fireBullets.push_back(i);
			break;
		}
	}
}


void AI::Seperation(float s) {
	if (s > 250) {
		// move to avg flock x pos
	}
	else {
		// move away avg flock x pos
	}
}

void AI::Alignment(float a){
	if (a > 5 || a < -5) {
		//  velocity to invers
	}
	else {
		// set velocity to match average
	}
}