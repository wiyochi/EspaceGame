#include <SFML/Graphics.hpp>
#include "skillTree/Tree.hpp"
#include "skillTree/Node.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Tree* t = new Tree();
	t->addSkill("sediment", "description de sediment");
	t->addSkill("miningDepth", "description de miningDepth");
	Node* cru = t->addSkill("crushing", "description de crushing");
	(*t)["crushing"]->addNeededNode((*t)["sediment"], 2);
	(*t)["crushing"]->addNeededNode((*t)["miningDepth"], 3);

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
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}