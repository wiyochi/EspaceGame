#include <SFML/Graphics.hpp>
#include "graphics/UI/Button.hpp"
#include <string>

int main()
{
    Button b("/resources/fonts/Roboto-Thin.ttf", "OUAIS OUAIS OUAIS");
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

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
        b.draw(window);
        
		window.display();
	}

	return 0;
}
