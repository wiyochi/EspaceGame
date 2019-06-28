#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "entities/loaders/Loader.h"
#include "map/Grid.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	sf::View v;
	float viewSpeed = 0.1f;

	Machine* m = Loader::loadMachine("resources/machines/copper_drill.json");
	std::cout << "Machine: " << *m << std::endl;

	Grid* mineGrid = new Grid(10, 10, sf::Vector2f(50.f, 50.f));

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
			default:
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			v.move(0, -viewSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			v.move(0, viewSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			v.move(-viewSpeed, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			v.move(viewSpeed, 0);

		window.setView(v);

		window.clear();
		window.draw(*m);
		window.draw(*mineGrid);
		window.display();
	}

	return 0;
}