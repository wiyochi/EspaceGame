#include <SFML/Graphics.hpp>
#include "graphics/UI/PoleButton.hpp"
#include <string>

int main()
{
    sf::View main_menu_view(sf::FloatRect(0, 0, 1280, 720));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    
    PoleButton pole1(0, window);
    PoleButton pole2(1, window);
    PoleButton pole3(2, window);
    PoleButton pole4(3, window);
    
    window.setView(main_menu_view);
    
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
                        but->action();
                    }
                }
            }
		}

		window.clear();
        
        
        pole1.draw();
        pole2.draw();
        pole3.draw();
        pole4.draw();
        
		window.display();
	}

	return 0;
}
