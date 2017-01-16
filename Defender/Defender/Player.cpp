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
	p_rotation = 0;
}

Player::~Player()
{

}


void Player::Update()
{
	shipSprite->setRotation(p_rotation);

	//displacement.x = (std::sin(p_rotation)) * shipSpeed.x;
	//displacement.y = (std::cos(p_rotation)) * shipSpeed.y;



	//double speedmagnitude = std::sqrt((shipSpeed.x * shipSpeed.x) + (shipSpeed.y * shipSpeed.y));
	//sf::Vector2f speedNormal = sf::Vector2f((shipSpeed.x / speedmagnitude), (shipSpeed.y / speedmagnitude));

	//displacement = sf::Vector2f(speedNormal.x * (std::cos(p_rotation)) - speedNormal.y * (std::sin(p_rotation)), speedNormal.x * (std::sin(p_rotation)) + speedNormal.y * (std::cos(p_rotation)));


	shipPos.x += shipSpeed.x;
	shipPos.y += shipSpeed.y;
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
		displacement.x += (std::cos(p_rotation)) * shipSpeed.x;
	}
	if (eve.key.code == sf::Keyboard::D) {
		if (shipSpeed.x <= 2)
		shipSpeed.x += 0.5f;
		displacement.x += (std::cos(p_rotation)) * shipSpeed.x;
	}
	if (eve.key.code == sf::Keyboard::W) {
		if (shipSpeed.y >= -5)
		shipSpeed.y -= 0.5f;
		displacement.y += (std::sin(p_rotation)) * shipSpeed.y;
	}
	if (eve.key.code == sf::Keyboard::S) {
		if (shipSpeed.y <= 5)
		shipSpeed.y += 0.5f;
		displacement.y += (std::sin(p_rotation)) * shipSpeed.y;
	}
	if (eve.key.code == sf::Keyboard::Q) {
		if (p_rotation > 0) {
			p_rotation -= 2;
		}
		else {
			p_rotation = 360;
		}
		
	}
	if (eve.key.code == sf::Keyboard::E) {
		p_rotation += 2;
		if (p_rotation < 360) {
			p_rotation += 2;
		}
		else {
			p_rotation = 0;
		}
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

