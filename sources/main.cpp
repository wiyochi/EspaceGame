#include <SFML/Graphics.hpp>
#include "graphics/UI/PoleButton.hpp"
#include <string>
#include "graphics/UI/Case.hpp"
#include <random>
#include <time.h>
#include "graphics/utils/TextureManager.hpp"

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

void stop() {
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

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				float x = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
				float y = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
				std::cout << "SREEN{" << event.mouseButton.x << ";" << event.mouseButton.y << "}   ||    GAME{" << x << ";" << y << "}" << std::endl;
				switch (STATE) {
					case MAIN_MENU:
						if (pole1.contains(x, y)) STATE = POLE_1;
						if (pole2.contains(x, y)) STATE = POLE_2;
						if (pole3.contains(x, y)) STATE = POLE_3;
						if (pole4.contains(x, y)) STATE = POLE_4;
						break;
					case POLE_1 ... POLE_4:
						STATE = MAIN_MENU;
				}

			}
		}

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

		window.display();
	}

	stop();

	return 0;
}
