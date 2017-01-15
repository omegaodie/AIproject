#include "Level.h"


Level::Level(const GameData& gdata, Player& p, sf::View& v) : gd(gdata), l_Player(p), view(v) {
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
}

bool Level::Update()
{
	l_Player.Update();
	moveWorld(l_Player.getPlayerPosition());
	return true;
}

void Level::getInput(sf::Event &eve) {
	l_Player.getInput(eve);
}

void Level::Draw(sf::RenderWindow &w){
	w.draw(*l_worldSprite);
	l_Player.Draw(w);
}

void Level::moveWorld(sf::Vector2f & ps)
{
	//if()
	view.setCenter(ps.x , ps.y);
}