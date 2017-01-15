#include "Button.h"
//
//I AM REPORT THE HARASS!!
Button::Button(const GameData& gamd) : gd(gamd){

}

void Button::Init(sf::Vector2f pos, int name ) {
	b_Pos = &pos;
	b_sprite =  sf::Sprite();
	b_string = gd.m_buttonNames[name];
	b_sprite.setTexture(gd.m_buttonTextures[name]);
	b_sprite.setPosition(*b_Pos);
	current = false;
	setState(false);// false for not clicked
}

void Button::Init( int name) {

	b_Pos = new sf::Vector2f(gd.m_butonRects[name].left, gd.m_butonRects[name].top);
	b_sprite = sf::Sprite();
	b_string = gd.m_buttonNames[name];
	b_sprite.setTexture(gd.m_buttonTextures[name]);
	b_sprite.setPosition(*b_Pos);
	//b_sprite.setTextureRect(gd.m_butonRects[name]);
	current = false;
	setState(false);// false for not clicked
}

void Button::checkClick(sf::Vector2i mousePos) {
	if (mousePos.x > b_Pos->x && mousePos.x<(b_Pos->x + b_sprite.getTextureRect().width))
	{
		if (mousePos.y>b_Pos->y && mousePos.y<(b_Pos->y + b_sprite.getTextureRect().height)) {
			current = !current;
		}
	}
	setState(current);
}



void Button::setState(bool b) {
	if (b) {
		//btn_texture->loadFromImage(*btn_image_Clicked, *btn_Box);
	}
	else {
		//btn_texture->loadFromImage(*btn_image_notClicked, *btn_Box);
	}
}

void Button::Update(sf::Event &eve) {
		//process mouse/key events in here
		if (eve.type == sf::Event::MouseButtonPressed && eve.type != sf::Event::MouseEntered) {
			sf::Vector2i mousePos = sf::Vector2i(eve.mouseButton.x, eve.mouseButton.y);
			checkClick(mousePos);
		}
}

void Button::Draw(sf::RenderWindow &w) {
	w.draw(b_sprite);
}

string Button::getName()
{
	return b_string;
}

bool Button::getState() {
	return current;
}