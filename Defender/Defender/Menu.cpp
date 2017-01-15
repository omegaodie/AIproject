#include "Menu.h"



Menu::Menu(const GameData& gmeD) : gd(gmeD) {
	m_backGroundSprite = sf::Sprite();
	for (int i = 0; i < gd.numbuttons; i++) {
		m_Btns.push_back(Button(gd));
	}
	play = false;
	exit = false;
}

void Menu::Init() {
	m_backGroundSprite.setTexture(gd.m_bgtexture);
	for (int i = 0; i < gd.numbuttons; i++) {
		m_Btns[i].Init(i);
	}
}

void Menu::Draw(sf::RenderWindow &w) {
	DrawBackground(w);
	DrawButtons(w);
}

void Menu::Update(sf::Event &eve) {
	for (std::vector<Button>::iterator it = m_Btns.begin(); it < m_Btns.end(); it++) {
		it->Update(eve);
		if (it->getState()) {
			if (it->getName() == "Play") {
				play = true;
			}
			else if (it->getName() == "Exit") {
				exit = true;
			}
		}
	}
}

int Menu::getState() {
	if (play) {
		return 1;
	}
	if (exit) {
		return 2;
	}
	if((!play)&&(!exit)) {
		return 0;
	}
}

void Menu::DrawBackground(sf::RenderWindow &w) {
	w.draw(m_backGroundSprite);
}

void Menu::DrawButtons(sf::RenderWindow &w) {
	for (std::vector<Button>::iterator it = m_Btns.begin(); it < m_Btns.end(); it++) {
		it->Draw(w);
	}
}

