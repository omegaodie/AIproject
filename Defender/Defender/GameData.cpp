#include "GameData.h"

GameData::GameData()
{
	loadGameData();
}

void GameData::loadGameData()
{
	gamedata = json::parse_file("assets/GameData.json");

	json& mGameData = gamedata;

	///////////////////MENU//////////////////
	m_BackgGroundImageFile = mGameData["main_menu"]["menuBackground"]["image_src"].as_string();

	m_backGroundimage =  sf::Image();
	m_bgtexture =  sf::Texture();

	m_backGroundimage.loadFromFile(m_BackgGroundImageFile);
	m_bgtexture.loadFromImage(m_backGroundimage);
	//m_bgsprite.setTexture(m_bgtexture);
	numbuttons = mGameData["main_menu"]["buttons"][0]["s"].as<int>();
	for (int i = 1; i <= numbuttons; i++) {

		m_buttonImages.push_back(sf::Image());
		m_buttonImages[i - 1].loadFromFile(mGameData["main_menu"]["buttons"][i]["image_src"].as_string());


		m_buttonTextures.push_back(sf::Texture());
		m_buttonTextures[i - 1].loadFromImage(m_buttonImages[i - 1]);

		m_butonRects.push_back(sf::IntRect(mGameData["main_menu"]["buttons"][i]["x"].as<int>(), mGameData["main_menu"]["buttons"][i]["y"].as<int>(),
			mGameData["main_menu"]["buttons"][i]["w"].as<int>(), mGameData["main_menu"]["buttons"][i]["h"].as<int>()));

		m_buttonNames.push_back(string(mGameData["main_menu"]["buttons"][i]["name"].as_string()));
	}



	///////////////////LEVELS//////////////////
	g_spaceSource = mGameData["game"]["g_details"]["src_SpaceImage"].as_string();

	g_backGroundimage = sf::Image();
	g_bgtexture = sf::Texture();

	g_backGroundimage.loadFromFile(g_spaceSource);
	g_bgtexture.loadFromImage(g_backGroundimage);

	w_Dimensions = sf::Vector2f();
	w_Dimensions.x = mGameData["game"]["g_details"]["x"].as<int>();
	w_Dimensions.y = mGameData["game"]["g_details"]["y"].as<int>();

	numLevels = mGameData["game"]["g_details"]["numLevels"].as<int>();
	for (int i = 0; i < numLevels; i++) {

		g_LevelImages.push_back(sf::Image());
		g_LevelImages[i].loadFromFile(mGameData["game"]["Levels"][i]["src_backGround"].as_string());


		m_LevelTextures.push_back(sf::Texture());
		m_LevelTextures[i].loadFromImage(g_LevelImages[i]);


		g_LevelNames.push_back(string(mGameData["game"]["Levels"][i]["name"].as_string()));

		l_playerSpawn.push_back(sf::Vector2f(mGameData["game"]["Levels"][i]["player_Spawn_X"].as<int>(), mGameData["game"]["Levels"][i]["player_Spawn_Y"].as<int>()));

		l_numAiUnits.push_back(aiUnits{ mGameData["game"]["Levels"][i]["num_totalAi"].as<int>(), mGameData["game"]["Levels"][i]["num_Astronaunts"].as<int>(),  mGameData["game"]["Levels"][i]["num_Nests"].as<int>(),  mGameData["game"]["Levels"][i]["num_Abductors"].as<int>(),  mGameData["game"]["Levels"][i]["num_Mutants"].as<int>() });
	}



	///////////////////PLAYER//////////////////
	p_shipSource = mGameData["Player"]["img_source"].as_string();

	p_shipImage = sf::Image();
	p_shipTexture = sf::Texture();

	p_shipImage.loadFromFile(p_shipSource);
	p_shipTexture.loadFromImage(p_shipImage);



	///////////////////AI//////////////////
	ai_astronautSource = mGameData["game"]["g_details"]["AI"]["src_astronaut"].as_string();

	ai_astronautDimensions = sf::Vector2f(mGameData["game"]["g_details"]["AI"]["astro_dims_x"].as<int>(), mGameData["game"]["g_details"]["AI"]["astro_dims_y"].as<int>());

	ai_astronautImage = sf::Image();
	ai_astronautTexture = sf::Texture();

	ai_astronautImage.loadFromFile(ai_astronautSource);
	ai_astronautTexture.loadFromImage(ai_astronautImage);

	ai_abductorSource = mGameData["game"]["g_details"]["AI"]["src_abductor"].as_string();
	ai_abductorDimensions = sf::Vector2f(mGameData["game"]["g_details"]["AI"]["abductor_dims_x"].as<int>(), mGameData["game"]["g_details"]["AI"]["abductor_dims_y"].as<int>());

	ai_abductorImage = sf::Image();
	ai_abductorTexture = sf::Texture();

	ai_abductorImage.loadFromFile(ai_abductorSource);
	ai_abductorTexture.loadFromImage(ai_abductorImage);

	ai_nestSource = mGameData["game"]["g_details"]["AI"]["src_nest"].as_string();
	ai_nestDimensions = sf::Vector2f(mGameData["game"]["g_details"]["AI"]["nest_dims_x"].as<int>(), mGameData["game"]["g_details"]["AI"]["nest_dims_y"].as<int>());

	ai_nestImage = sf::Image();
	ai_nestTexture = sf::Texture();

	ai_nestImage.loadFromFile(ai_nestSource);
	ai_nestTexture.loadFromImage(ai_nestImage);
}