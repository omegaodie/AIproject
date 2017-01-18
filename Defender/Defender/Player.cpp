#include "Player.h"


Player::Player(const GameData& gdata) : gd(gdata)
{
	shipSprite = new sf::Sprite();
	for (int i = 0; i < 100; i++) {
		p_Bullets.push_back(Bullet(gd));
	}
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

Bullet& Player::getBullet(int i) {
	return p_Bullets[i];
}


void Player::Update()
{
	if (hp <= 0) {
		alive = false;
	}
	for (int i = 0; i < 100; i++) {
		if (p_Bullets[i].getAlive() == true) {
			p_Bullets[i].Update();
		}
	}
	for (int i = 0; i < p_BulletsFire.size(); i++) {
		if (p_Bullets[p_BulletsFire[i]].getAlive() == false) {
			p_Bullets[p_BulletsFire[i]].reset();
		}
	}

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
		if (shipSpeed.x >= -500) {
			shipSpeed.x -= 5;
			displacement.x += shipSpeed.x;
			if (!movingLeft) {
				turning = true;
			}
		}
	}
	if (eve.key.code == sf::Keyboard::D) {
		if (shipSpeed.x <= 500) {
			shipSpeed.x += 5;
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
	if (eve.key.code == sf::Keyboard::Space) {
		fire();
	}
}

void Player::Draw(sf::RenderWindow &w)
{
	w.draw(*shipSprite);
	for (int i = 0; i < 100; i++) {
		if (p_Bullets[i].getAlive() == true) {
			p_Bullets[i].Draw(w);
		}
	}
}

sf::Vector2f& Player::getPlayerPosition() 
{
	return shipPos;
}

vector<int> Player::getBulletsFired() {
	return p_BulletsFire;
}

void Player::fire()
{
	for (int i = 0; i < 100; i++) {
		if (p_Bullets[i].getAlive() != true) {
			p_Bullets[i].init(shipPos, shipSpeed, p_rotation);
			p_BulletsFire.push_back(i);
			break;
		}
	}
}

void Player::isHit() {
	hp - 5;
}