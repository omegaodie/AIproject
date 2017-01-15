//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "GameManager.h"




////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML Application");//where we draw things
	window.setFramerateLimit(60);
	sf::View theView;
	theView = sf::View();
	theView.reset(sf::FloatRect(0, 0, 1024, 1024));
	theView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	
	GameManager *the_Game = new GameManager();//our game, everything happens here
	the_Game->Init(theView);
	while (window.isOpen()) {
		window.clear();
		the_Game->Run(window);// we are passing  REFERENCE to the window down to the objects they draw on it themselves
		window.setView(theView);
		window.display();
	}

	return EXIT_SUCCESS;
}
