#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "entities/JSonInterface/Loader.hpp"
#include "entities/JSonInterface/Writer.hpp"
#include "entities/map/Grid.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	sf::View v;
	float viewSpeed = 0.1f;

	Grid* poles[4] = { nullptr };

	Loader::loadItems("resources/item/items.json");
	Loader::loadSave("resources/saves/saveTest.json", poles);

	bool stop = false;

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

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !stop)
		{
			stop = true;
			Writer::save("resources/saves/testWriter.json", poles);
		}
		else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && stop)
		{
			stop = false;
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

	// Liberation memoire des poles (machines)
	for(size_t i = 0; i < 4; i++)
	{
		if(poles[i] != nullptr)
			delete poles[i];
	}

	// Liberation memoire des items
	Item::deleteItems();
	

	return 0;
}