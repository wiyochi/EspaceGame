#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum Item
{
	iron_ore,
	copper_ore
};

class Machine
{
public:
	Machine(std::string filename_texture, sf::Vector2f pos, Item in, Item out);
	~Machine();

private:
	sf::Texture		m_texture;
	sf::Vector2f	m_position;
	Item			m_itemIn;
	Item			m_itemOut;
};

