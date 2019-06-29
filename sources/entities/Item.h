#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Item
{
public:
	static std::vector<Item*> items;
	static Item* findItem(std::string name);

	Item(std::string className, std::string name, std::string textureFileName);
	~Item();
	std::string getName() const;
	std::string getClass() const;

private:
	std::string m_name;
	std::string m_class;
	sf::Texture m_texture;
};