#include <SFML/Graphics.hpp>
#include "graphics/UI/PoleButton.hpp"
#include <string>

int main()
{
    PoleButton pole1(0);
    PoleButton pole2(1);
    PoleButton pole3(2);
    PoleButton pole4(3);
    /*
    Button pole2("resources/fonts/Roboto-Thin.ttf", L"Pôle 2", sf::Vector2f(640, 360));
    Button pole3("resources/fonts/Roboto-Thin.ttf", L"Pôle 3", sf::Vector2f(640, 360));
    Button pole4("resources/fonts/Roboto-Thin.ttf", L"Pôle 4", sf::Vector2f(640, 360));
    */
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    
    
    
    
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
        
        
        pole1.draw(window);
        pole2.draw(window);
        pole3.draw(window);
        pole4.draw(window);
        
		window.display();
	}

	return 0;
}
