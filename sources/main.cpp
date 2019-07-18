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

	// View (débug)
	sf::View v;
	float viewSpeed = 0.5f;

	// Game Time
	sf::Clock clock;
	sf::Time elapsedTime;
	int	deltaTime;

	// Poles declaration
	Grid* poles[4] = { nullptr };

	// Load game objetcs
	Loader::loadItems("resources/item/items.json");
	Loader::loadSave("resources/save/saveTest.json", poles);
	Tree* t = Loader::loadSkillTree("resources/skillTree/test.json");
	t->setPosition(sf::Vector2f(900.f, 20.f));
	t->initLinks();

	bool keyPressed_S = false;

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
			default:
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
		window.setView(v);

		window.clear();

		// Draws
		for (size_t i = 0; i < 4; i++)
			window.draw(*(poles[i]));
		window.draw(*t);

		window.display();
	}

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