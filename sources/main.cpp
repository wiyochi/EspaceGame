#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <rapidjson/document.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	std::ifstream file("resources/saves/saveTest.json", std::ios::in);
	std::string str;

	if (file)
	{
		char c;
		while (file.get(c))
			str.push_back(c);

		file.close();
	}
	else
	{
		std::cout << "Erreur load file" << std::endl;
	}

	const char* json = str.c_str();
	rapidjson::Document d;
	d.Parse(json);

	rapidjson::Value& s = d["mine"]["machines"];
	for (rapidjson::SizeType i = 0; i < s.Size(); i++)
		std::cout << s[i]["machine"].GetType() << std::endl;

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	d.Accept(writer);

	std::cout << buffer.GetString() << std::endl;

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