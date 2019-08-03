#include <SFML/Graphics.hpp>
#include "graphics/UI/PoleButton.hpp"
#include <string>
#include "graphics/UI/Case.hpp"
#include <random>
#include <time.h>
#include "graphics/utils/TextureManager.hpp"

typedef enum {
	MAIN_MENU,
} GAME_STATE;

GAME_STATE STATE = MAIN_MENU;
long debug = 0;
long debug2 = 0;


void loading()
{
	loadTexture("DIRT", "resources/textures/tiles/dirt.png");
	loadTexture("STONE", "resources/textures/tiles/stone.png");
	loadTexture("WATER", "resources/textures/tiles/water.png");
	loadTexture("GRASS", "resources/textures/tiles/grass.png");
}

void stop()
{
	freeTextureManager();
}




int main() {


	loading();

	//sf::View main_menu_view(sf::FloatRect(0, 0, 1280, 720));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	PoleButton pole1(0, window);
	PoleButton pole2(1, window);
	PoleButton pole3(2, window);
	PoleButton pole4(3, window);

	//sf::View _view(sf::FloatRect(0, 0, 70000, 1700));
	//window.setView(_view);

	std::default_random_engine re(time(0));
	std::uniform_int_distribution<int> distrib(0, 255);

	while (window.isOpen()) {
		debug++;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				std::cout << "{" << event.mouseButton.x << ";" << event.mouseButton.y << "}" << std::endl;
				float x = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
				float y = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
				/* switch (STATE) {
				 case MAIN_MENU :
				 if (pole1.contains(x, y))
				 pole1.action();
				 if (pole2.contains(x, y))
				 pole2.action();
				 if (pole3.contains(x, y))
				 pole3.action();
				 if (pole4.contains(x, y))
				 pole4.action();
				 break;

				 }
				 */

			}
		}

		window.clear();

		pole1.action();
		pole1.draw();
		pole2.action();
		pole2.draw();
		pole3.action();
		pole3.draw();
		pole4.action();
		pole4.draw();


		window.display();
		//  std::cout << "DEBUG : " << debug << std::endl;
		/*if (debug > 100)
		 return 1;
		 */
	}

	stop();

	return 0;
}
