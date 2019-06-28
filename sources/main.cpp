#include <SFML/Graphics.hpp>
#include "graphics/UI/PoleButton.hpp"
#include <string>

int main()
{
    PoleButton pole1(0);
    PoleButton pole2(1);
    PoleButton pole3(2);
    PoleButton pole4(3);
    
    
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "{" << event.mouseButton.x << ";" << event.mouseButton.y << "}" << std::endl;
                
                for (auto const& but: Button::_buttons)
                {
                    float x = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
                    float y = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
                    if (but->contains(x, y))
                    {
                        
                    }
                }
            }
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
