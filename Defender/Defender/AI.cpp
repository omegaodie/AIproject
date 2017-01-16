#include "AI.h"


AI::AI(const GameData& gdata) : gd(gdata) {
	e_Sprite = sf::Sprite();
	e_Pos = sf::Vector2f();
}

void AI::init(int ln, int t)
{
	e_Pos.x = t * 100;
	e_Pos.y = 40;
	e_type = t;
	if (e_type == ASTRONAUT) {
		e_Sprite.setTexture(gd.ai_astronautTexture);
	}
	else if (e_type == NEST)
	{
		e_Sprite.setTexture(gd.ai_nestTexture);
	}
	else if (e_type == ABDUCTOR)
	{
		e_Sprite.setTexture(gd.ai_abductorTexture);
	}
	else { //MUTANT
		   //e_Sprite.setTexture(gd.ai_);
	}

	timer = 120;

	e_Sprite.setPosition(e_Pos);

}


void AI::init(sf::Vector2f* p, int ln, int t)
{
	e_Pos.x = p->x;
	e_Pos.y = p->y;
	e_type = t;
	if (e_type == ASTRONAUT) {
		e_Sprite.setTexture(gd.ai_astronautTexture);
	}
	else if (e_type == NEST)
	{
		e_Sprite.setTexture(gd.ai_nestTexture);
	}
	else if (e_type == ABDUCTOR)
	{
		e_Sprite.setTexture(gd.ai_abductorTexture);
	}
	else { //MUTANT
		//e_Sprite.setTexture(gd.ai_);
	}

	timer = 120;
	
	e_Sprite.setPosition(e_Pos);

}


float AI::getTimer() {
	return timer;
}

void AI::Update()
{
	timer -= 0.5;
	e_Pos.x += e_direction.x;
	e_Pos.y += e_direction.y;
	e_Sprite.setPosition(e_Pos);
}


void AI::setDirection(sf::Vector2f & d)
{
	e_direction = d;
	timer = 120;
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
