#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <memory>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "jsoncons\json.hpp"

using jsoncons::json;
using jsoncons::json_exception;
using jsoncons::pretty_print;
using jsoncons::json_deserializer;
using namespace std;

class GameData {
private:
	json gamedata;

	void loadGameData();

public:
	GameData::GameData();


	//MENU//
	string m_BackgGroundImageFile, m_ButtonImageFile;
	sf::Image m_backGroundimage;
	sf::Texture m_bgtexture;
	int numbuttons;
	vector<string> m_buttonNames;
	vector<sf::Image> m_buttonImages;
	vector<sf::Texture> m_buttonTextures;
	vector<sf::IntRect> m_butonRects;



	///LEVELS/////////
	string g_spaceSource;
	sf::Image g_backGroundimage;
	sf::Texture g_bgtexture;
	int numLevels;
	vector<string> g_LevelNames;
	vector<sf::Image> g_LevelImages;
	vector<sf::Texture> m_LevelTextures;
	vector<sf::Vector2f> l_playerSpawn;


	////////PLAYER/////////////////////////
	string p_shipSource;
	sf::Image p_shipImage;
	sf::Texture p_shipTexture;
	sf::Vector2f p_shipDimensions;
	

};

#endif