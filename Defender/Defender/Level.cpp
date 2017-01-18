#include "Level.h"


Level::Level(const GameData& gdata, Player& p, sf::View& v) : gd(gdata), l_Player(p), view(v), l_AIM(gdata, p), cm(gdata) {
	view.reset(sf::FloatRect(0, 0, 1024, 1024));
	
}

void Level::init(int ln)
{

	l_Num = ln;
	l_worldSprite = new sf::Sprite();
	l_worldSprite->setTexture(gd.g_bgtexture);
	l_Player.Init(ln);
	l_worldSpritePos = sf::Vector2f(0, 0);
	l_worldSprite->setPosition(l_worldSpritePos);
	l_worldSprite->setScale(1, 0.5);
	l_AIM.init(ln);
}


void Level::Collisions() {
	for (int i = 0; i < l_Player.getBulletsFired().size(); i++) {
  		for (int k = 0; k < gd.l_numAiUnits[l_Num].nests; k++) {
			if (l_AIM.getNests(k).getAlive()) {
				if (cm.getcollision(sf::IntRect(l_AIM.getNests(k).getPosition().x, l_AIM.getNests(k).getPosition().y, 256, 256),
					sf::IntRect(l_Player.getBullet(i).getPosition().x, l_Player.getBullet(i).getPosition().y, 12, 24))) {
					l_AIM.getNests(k).setAlive(false);
				}
			}
		}
		for (int k = 0; k < gd.l_numAiUnits[l_Num].abductors; k++) {
			if (l_AIM.getAbductors(k).getAlive()) {
				if (cm.getcollision(sf::IntRect(l_AIM.getAbductors(k).getPosition().x, l_AIM.getAbductors(k).getPosition().y, 64, 64),
					sf::IntRect(l_Player.getBullet(i).getPosition().x, l_Player.getBullet(i).getPosition().y, 12, 24))) {
					l_AIM.getAbductors(k).setAlive(false);
				}
			}
		}
		for (int k = 0; k < gd.l_numAiUnits[l_Num].mutants; k++) {
			if (l_AIM.getMutants(k).getAlive()) {
				if (cm.getcollision(sf::IntRect(l_AIM.getMutants(k).getPosition().x, l_AIM.getMutants(k).getPosition().y, 64, 64),
					sf::IntRect(l_Player.getBullet(i).getPosition().x, l_Player.getBullet(i).getPosition().y, 12, 24))) {
					l_AIM.getMutants(k).setAlive(false);
				}
			}
		}
	}

	for (int k = 0; k < gd.l_numAiUnits[l_Num].abductors; k++) {
		if (l_AIM.getAbductors(k).getAlive()) {
			for (int z = 0; z < 10; z++) {
				if (l_AIM.getAbductors(k).getBullet(z).getAlive()) {
					if (cm.getcollision(sf::IntRect(l_AIM.getAbductors(k).getBullet(z).getPosition().x, l_AIM.getAbductors(k).getBullet(z).getPosition().y, 12, 24),
						sf::IntRect(l_Player.getBullet(z).getPosition().x, l_Player.getBullet(z).getPosition().y, 128, 128))) {
						l_Player.isHit();
					}
				}
			}
		}
	}
	for (int k = 0; k < gd.l_numAiUnits[l_Num].mutants; k++) {
		if (l_AIM.getMutants(k).getAlive()) {
			for (int z = 0; z < 10; z++) {
				if (l_AIM.getMutants(k).getBullet(z).getAlive()) {
					if (cm.getcollision(sf::IntRect(l_AIM.getMutants(k).getBullet(z).getPosition().x, l_AIM.getMutants(k).getBullet(z).getPosition().y, 12, 24),
						sf::IntRect(l_Player.getBullet(z).getPosition().x, l_Player.getBullet(z).getPosition().y, 128, 128))) {
						l_Player.isHit();
					}
				}
			}
		}
	}
}



bool Level::Update()
{
	Collisions();
	l_Player.Update();
	l_AIM.Update();
	moveWorld(l_Player.getPlayerPosition());

	return true;
}

void Level::getInput(sf::Event &eve) {
	l_Player.getInput(eve);
}

void Level::Draw(sf::RenderWindow &w){
	w.draw(*l_worldSprite);
	l_AIM.Draw(w);
	l_Player.Draw(w);
}

void Level::moveWorld(sf::Vector2f & ps)
{
	if ((ps.x > 512) && (ps.x < gd.w_Dimensions.x - 512)) {
		view.setCenter(ps.x, 512);
	}
	
}