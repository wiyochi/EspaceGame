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

	Item(std::string name, std::string className, std::string textureFileName);
	~Item();
	std::string getName();
	std::string getClassName();

	friend std::ostream& operator<<(std::ostream& out, Item& i);

private:
	std::string m_name;
	std::string m_className;
	sf::Texture m_texture;
};