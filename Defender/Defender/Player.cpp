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
	p_rotation = 90;
	movingLeft = false;
}

Player::~Player()
{

}


void Player::Update()
{
	shipSprite->setRotation(p_rotation);

	if ((shipPos.x >= 128) && (shipPos.x <= gd.w_Dimensions.x - 128)) {
		shipPos.x += shipSpeed.x;
	}
	else {
		//stuff
		if (shipPos.x <= 128) {
			shipPos.x += 8;
			shipSpeed.x = 0.5;
		}
		else {
			shipPos.x -= 8;
			shipSpeed.x = -0.5;
		}
	}
	if ((shipPos.y >= 128) && (shipPos.y <= (gd.w_Dimensions.y / 2) - 128)) {
		shipPos.y += shipSpeed.y;
	}
	else {
		//stuff

		if (shipPos.y <= 128) {
			shipPos.y += 8;
			shipSpeed.y = 0.5;
		}
		else {
			shipPos.y -= 8;
			shipSpeed.y = -0.5;
		}
	}
	shipSprite->setPosition(shipPos);
	if (shipSpeed.x > 0) {
		shipSpeed.x -= 0.005;
	}
	if (shipSpeed.x < 0) {
		shipSpeed.x += 0.005;
	}

	if (shipSpeed.y > 0) {
		shipSpeed.y -= 0.005;
	}
	if (shipSpeed.y < 0) {
		shipSpeed.y += 0.005;
	}
	if (turning) {
		if (!movingLeft) {
			if (p_rotation > -90) {
				p_rotation -= 2;
			}
			else {
				movingLeft = true;
				turning = false;
			}
		}else {
			if (p_rotation < 90) {
				p_rotation += 2;
			}
			else {
				movingLeft = false;
				turning = false;
			}
		}
	}
}

void Player::getInput(sf::Event& eve)
{
	if (eve.key.code == sf::Keyboard::A) {
		if (shipSpeed.x >= -5) {
			shipSpeed.x -= 0.5f;
			displacement.x += shipSpeed.x;
			if (!movingLeft) {
				turning = true;
			}
		}
	}
	if (eve.key.code == sf::Keyboard::D) {
		if (shipSpeed.x <= 5) {
			shipSpeed.x += 0.5f;
			displacement.x += shipSpeed.x;
			if (movingLeft) {
				turning = true;
			}
		}
	}
	if (eve.key.code == sf::Keyboard::W) {
		if (shipSpeed.y >= -5) {
			shipSpeed.y -= 0.5f;
			displacement.y += shipSpeed.y;
		}
	}
	if (eve.key.code == sf::Keyboard::S) {
		if (shipSpeed.y <= 5) {
			shipSpeed.y += 0.5f;
			displacement.y += shipSpeed.y;
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

