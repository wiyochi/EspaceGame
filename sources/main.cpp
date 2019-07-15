#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "JSonInterface/Loader.hpp"
#include "JSonInterface/Writer.hpp"
#include "map/Grid.hpp"
#include "skillTree/Tree.hpp"
#include "skillTree/Node.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	sf::View v;
	float viewSpeed = 0.1f;

	Grid* poles[4] = { nullptr };

	Loader::loadItems("resources/item/items.json");
	Loader::loadSave("resources/save/saveTest.json", poles);
	Tree* t = Loader::loadSkillTree("resources/skillTree/test.json");

	bool stop = false;

    //Affichage debug des items load
	for(unsigned int i = 0; i < Item::items.size(); i++)
	{
		std::cout << "Item " << i << ": " << *(Item::items[i]) << std::endl;
	}

	//Affichage debug des machines des poles
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "Pole " << poles[i]->getName() << std::endl;
		for(const auto machine : poles[i]->getMachines())
		{
			std::cout << *(machine) << std::endl;
		}
	}

	(*t)["sediment"]->increase();
	(*t)["miningDepth"]->increase();
	(*t)["miningDepth"]->increase();
	(*t)["miningDepth"]->increase();
	(*t)["miningDepth"]->increase();

	(*t)["crushing"]->increase();
	std::cout << "### AVANT ###" << std::endl << *t << std::endl;

	(*t)["sediment"]->increase();
	(*t)["crushing"]->increase();
	std::cout << "### APRES ###" << std::endl << *t << std::endl;

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
			case sf::Event::KeyReleased:
				if(event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			default:
				break;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !stop)
		{
			stop = true;
			std::cout << "Sauvegarde..." << std::endl;
			Writer::save("resources/save/testWriter.json", poles);
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
		for (size_t i = 0; i < 4; i++)
			window.draw(*(poles[i]));
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
	
	delete t;

	return 0;
}