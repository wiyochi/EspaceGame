#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "entities/loaders/Loader.hpp"
#include "entities/map/Grid.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	sf::View v;
	float viewSpeed = 0.1f;

	Grid* poles[4];

	Loader::loadItems("resources/item/items.json");
	Loader::loadSave("resources/saves/saveTest.json", poles);

    //Affichage debug des items load
	for(unsigned int i = 0; i < Item::items.size(); i++)
	{
		std::cout << "Item " << i << ": " << *(Item::items[i]) << std::endl;
	}

	//Affichage debug des machines du pole mine
	std::vector<Machine*> machines = poles[0]->getMachines();
	for(unsigned int i = 0; i < machines.size(); i++)
	{
		std::cout << "Machine " << i << ": " << *(machines[i]) << std::endl;
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
		window.draw(*(poles[0]));
		window.display();
	}

	return 0;
}