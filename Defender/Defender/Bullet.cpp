#include "Bullet.h"

Bullet::Bullet(const GameData& gdata) : gd(gdata)
{
	b_Pos = sf::Vector2f();
	b_direction = sf::Vector2f();
	b_Sprite = sf::Sprite();
}


void Bullet::init(sf::Vector2f& s, sf::Vector2f& dir, float rot) {
	timer = 0;
	b_Pos = s;
	b_Sprite.setTexture(gd.b_Texture);
	b_Sprite.setRotation(90);
	b_rotation = rot - 90;
	//b_Sprite.setScale(sf::Vector2f(10, 10));
	b_Speed = 20;
	
	float cs = std::cos(b_rotation * PI / 180.0);
	float sn = std::sin(b_rotation * PI / 180.0);

	//float cs = std::cos(rot);
	//float sn = std::sin(rot);
	float unitLenght = std::sqrt(b_Speed * b_Speed);


	b_direction.x = ((b_Speed * cs) / unitLenght) * b_Speed;
	b_direction.y = ((b_Speed * sn) / unitLenght) * b_Speed;

	


	b_alive = true;
	
}

Bullet::~Bullet()
{
}

void Bullet::setAlive(bool b){
	b_alive = b;
}

bool Bullet::getAlive() {
	return b_alive;
}

void Bullet::reset()
{
	b_Pos = sf::Vector2f();
	b_direction = sf::Vector2f();
}

sf::Vector2f & Bullet::getPosition()
{
	return b_Pos;
}

void Bullet::Update()
{
	if (timer >= 60) {
		b_alive = false;
	}
   	b_Pos.x += (b_direction.x);
	b_Pos.y += (b_direction.y);

    b_Sprite.setPosition(b_Pos);
	timer++;
}

void Bullet::Draw(sf::RenderWindow &w)
{
	w.draw(b_Sprite);
}
