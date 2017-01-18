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



typedef struct {
	int total;
	int astronauts;
	int nests;
	int abductors;
	int mutants;
	int c_astronauts;
	int c_nests;
	int c_abductors;
	int c_mutants;
} aiUnits;



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
	sf::Vector2f w_Dimensions;

	string g_spaceSource;
	sf::Image g_backGroundimage;
	sf::Texture g_bgtexture;
	int numLevels;
	vector<string> g_LevelNames;
	vector<sf::Image> g_LevelImages;
	vector<sf::Texture> m_LevelTextures;
	vector<sf::Vector2f> l_playerSpawn;
	vector<aiUnits> l_numAiUnits;


	////////PLAYER/////////////////////////
	string p_shipSource;
	sf::Image p_shipImage;
	sf::Texture p_shipTexture;
	sf::Vector2f p_shipDimensions;



	////////AI/////////////////////////
	string ai_astronautSource;
	sf::Image ai_astronautImage;
	sf::Texture ai_astronautTexture;
	sf::Vector2f ai_astronautDimensions;

	string ai_abductorSource;
	sf::Image ai_abductorImage;
	sf::Texture ai_abductorTexture;
	sf::Vector2f ai_abductorDimensions;

	string ai_nestSource;
	sf::Image ai_nestImage;
	sf::Texture ai_nestTexture;
	sf::Vector2f ai_nestDimensions;

	////////BOOMBOOM/////////////////////////
	string boom_source;
	sf::Image b_Image;		// The player bullet texture
	sf::Texture b_Texture;			// The enemy bullet texture
	

};

#endif