#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "graphics/UI/PoleButton.hpp"
#include <string>
#include "graphics/UI/Case.hpp"
#include <random>
#include <time.h>
#include "graphics/utils/TextureManager.hpp"
#include "JSonInterface/Loader.hpp"
#include "JSonInterface/Writer.hpp"
#include "map/Grid.hpp"
#include "skillTree/Tree.hpp"
#include "skillTree/Node.hpp"

typedef enum {
	MAIN_MENU, POLE_1, POLE_2, POLE_3, POLE_4,
} GAME_STATE;

GAME_STATE STATE = MAIN_MENU;

void loading() {
	loadTexture("DIRT", "resources/textures/tiles/dirt.png");
	loadTexture("STONE", "resources/textures/tiles/stone.png");
	loadTexture("WATER", "resources/textures/tiles/water.png");
	loadTexture("GRASS", "resources/textures/tiles/grass.png");
}

void stoping() {
	freeTextureManager();
}

int main() {

	loading();
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	PoleButton pole1(0, window);
	PoleButton pole2(1, window);
	PoleButton pole3(2, window);
	PoleButton pole4(3, window);

	//sf::View _view(sf::FloatRect(0, 0, 70000, 1700));
	//window.setView(_view);

	// View (d�bug)
	sf::View v;
	float viewSpeed = 0.5f;

	// Game Time
	sf::Clock clock;
	sf::Time elapsedTime;
	int	deltaTime;

	// Poles declaration
	Grid* poles[4] = { nullptr };

	Tree* t = nullptr;

	// Load game objetcs
	Loader::loadItems("resources/item/items.json");
	Loader::loadSave("resources/save/saveTest.json", poles);
	if (Loader::loadSkillTree("resources/skillTree/test.json", &t))
	{
		t->setPosition(sf::Vector2f(900.f, 20.f));
		t->initLinks();
	}

	bool keyPressed_S = false;

	for (unsigned int i = 0; i < Item::items.size(); i++)
	{
		std::cout << "Item " << i << " : " << *(Item::items[i]) << std::endl;
	}

	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "Pole " << poles[i]->getName() << std::endl;
		for (const auto machine : poles[i]->getMachines())
		{
			std::cout << *(machine) << std::endl;
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseWheelScrolled:
				// Zoom and dezoom camera
				if (event.mouseWheelScroll.delta < 0)
				{
					v.zoom(1.1f);
					viewSpeed *= 1.1f;
				}
				else
				{
					v.zoom(0.9f);
					viewSpeed *= 0.9f;
				}
				break;
			case sf::Event::KeyReleased:
				if(event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
            case sf::Event::MouseButtonPressed:
				float x = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
				float y = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
				std::cout << "SREEN{" << event.mouseButton.x << ";" << event.mouseButton.y << "}   ||    GAME{" << x << ";" << y << "}" << std::endl;
				switch (STATE) 
                {
					case MAIN_MENU:
						if (pole1.contains(x, y)) STATE = POLE_1;
						if (pole2.contains(x, y)) STATE = POLE_2;
						if (pole3.contains(x, y)) STATE = POLE_3;
						if (pole4.contains(x, y)) STATE = POLE_4;
						break;
					case POLE_1 ... POLE_4:
						STATE = MAIN_MENU;
                        break;
				}
				break;
			}
		}

		// Get delta time between 2 frames
		elapsedTime = clock.getElapsedTime();
		clock.restart();
		deltaTime = elapsedTime.asMilliseconds();

		// S key to save actual poles
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !keyPressed_S)
		{
			keyPressed_S = true;
			std::cout << "Sauvegarde..." << std::endl;
			Writer::save("resources/save/testWriter.json", poles);
		}
		else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && keyPressed_S)
		{
			keyPressed_S = false;
		}

		// Arrows to move camera
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			v.move(0, -viewSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			v.move(0, viewSpeed * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			v.move(-viewSpeed * deltaTime, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			v.move(viewSpeed * deltaTime, 0);

		// Updates
		t->update(window);
		for (const auto pole : poles)
			pole->update(window);
		window.setView(v);

		window.clear();
		switch (STATE) {
			case MAIN_MENU:
				pole1.setMapMode(Map::SPLITSCREEN);
				pole2.setMapMode(Map::SPLITSCREEN);
				pole3.setMapMode(Map::SPLITSCREEN);
				pole4.setMapMode(Map::SPLITSCREEN);
				break;
			case POLE_1:
				pole1.setMapMode(Map::FULLSCREEN);
				pole2.setMapMode(Map::NO_SCREEN);
				pole3.setMapMode(Map::NO_SCREEN);
				pole4.setMapMode(Map::NO_SCREEN);
				break;
			case POLE_2:
				pole1.setMapMode(Map::NO_SCREEN);
				pole2.setMapMode(Map::FULLSCREEN);
				pole3.setMapMode(Map::NO_SCREEN);
				pole4.setMapMode(Map::NO_SCREEN);
				break;
			case POLE_3:
				pole1.setMapMode(Map::NO_SCREEN);
				pole2.setMapMode(Map::NO_SCREEN);
				pole3.setMapMode(Map::FULLSCREEN);
				pole4.setMapMode(Map::NO_SCREEN);
				break;
			case POLE_4:
				pole1.setMapMode(Map::NO_SCREEN);
				pole2.setMapMode(Map::NO_SCREEN);
				pole3.setMapMode(Map::NO_SCREEN);
				pole4.setMapMode(Map::FULLSCREEN);
				break;
			default:
				break;
		}

		pole1.draw();
		pole2.draw();
		pole3.draw();
		pole4.draw();


		// Draws
		for (size_t i = 0; i < 4; i++)
			window.draw(*(poles[i]));
		window.draw(*t);

		window.display();
	}

	stoping();

	// Liberation memoire des poles (machines)
	// Poles and machines memory release
	for(size_t i = 0; i < 4; i++)
	{
		if(poles[i] != nullptr)
			delete poles[i];
	}

	// Items memory release
	Item::deleteItems();
	
	// Tree test memory release
	delete t;

	return 0;
}
