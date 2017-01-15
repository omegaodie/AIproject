#include "Player.h"


Player::Player(const GameData& gdata) : gd(gdata)
{
	shipSprite = new sf::Sprite();
}

void Player::Init(int ln) {
	
	shipSprite->setTexture(gd.p_shipTexture);
	shipSprite->setOrigin(64, 64);
	shipPos = sf::Vector2f(gd.l_playerSpawn[ln]);
	playerHealth = 100;
	shipSpeed = sf::Vector2f(0, 0);
}

Player::~Player()
{

}


void Player::Update()
{
	displacement.x = (std::sin(shipSprite->getRotation())) * shipSpeed.x;
	displacement.y = (std::cos(shipSprite->getRotation())) * shipSpeed.y;

	shipPos.x += displacement.x;
	shipPos.y += displacement.y;
	shipSprite->setPosition(shipPos);
	if (shipSpeed.x > 0) {
		shipSpeed.x -= 0.005f;
	}
	else if (shipSpeed.x < 0) {
		shipSpeed.x += 0.005f;
	}
	if (shipSpeed.y > 0) {
		shipSpeed.y -= 0.005f;
	}
	else if (shipSpeed.y < 0) {
		shipSpeed.y += 0.005;
	}

}

void Player::getInput(sf::Event& eve)
{
	if (eve.key.code == sf::Keyboard::A) {
		if(shipSpeed.x >= -2)
		shipSpeed.x -= 0.5f;
	}
	if (eve.key.code == sf::Keyboard::D) {
		if (shipSpeed.x <= 2)
		shipSpeed.x += 0.5f;
	}
	if (eve.key.code == sf::Keyboard::W) {
		if (shipSpeed.y >= -5)
		shipSpeed.y -= 0.5f;
	}
	if (eve.key.code == sf::Keyboard::S) {
		if (shipSpeed.y <= 5)
		shipSpeed.y += 0.5f;
	}
	if (eve.key.code == sf::Keyboard::Q) {
		shipSprite->setRotation(shipSprite->getRotation() - 2);
	}
	if (eve.key.code == sf::Keyboard::E) {
		shipSprite->setRotation(shipSprite->getRotation() + 2);
	}
}

void Player::Draw(sf::RenderWindow &w)
{
	w.draw(*shipSprite);
}

sf::Vector2f& Player::getPlayerPosition() 
{
	return shipPos;
}

