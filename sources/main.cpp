#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	sf::RectangleShape rs(sf::Vector2f(200.f, 200.f));
	rs.setPosition(sf::Vector2f(500.f, 500.f));
	rs.setFillColor(sf::Color::Blue);

	// View (d�bug)
	sf::View v;
	float viewSpeed = 2.f;
	float camSpeed = 0.f;

	// Game Time
	sf::Clock clock;
	sf::Time elapsedTime;
	int	deltaTime;

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
			}
		}

		// Get delta time between 2 frames
		elapsedTime = clock.getElapsedTime();
		clock.restart();
		deltaTime = elapsedTime.asMilliseconds();

		// Arrows to move camera
		camSpeed = viewSpeed * deltaTime;
		std::cout << "test" << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			v.move(0, -camSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			v.move(0, camSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			v.move(-camSpeed, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			v.move(camSpeed, 0);

		// Updates
		window.setView(v);

		window.clear();

		// Draws
		window.draw(rs);

		window.display();
	}

	return 0;
}
