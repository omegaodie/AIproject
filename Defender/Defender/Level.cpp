#include "Level.h"


Level::Level(const GameData& gdata, Player& p, sf::View& v) : gd(gdata), l_Player(p), view(v), l_AIM(gdata){
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

bool Level::Update()
{
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