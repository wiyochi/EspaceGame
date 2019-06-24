#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

/*   Enum Item
 * Contient actuellement tousles items créés et utilisés par les machines
 * Est temporaire puisque l'objectif est de load tous les items depuis un json
*/
enum Item
{
	null,
	iron_ore,
	copper_ore
};

Item stringToItem(std::string str_item);
std::string itemToString(Item item);

class Machine
{
public:
	Machine(std::string filename_texture, Item in, Item out, float energy);
	~Machine();
	friend std::ostream& operator<<(std::ostream& out, Machine& m);

private:
	sf::Texture		m_texture;
	sf::Vector2f	m_position;
	Item			m_itemIn;
	Item			m_itemOut;
	float			m_energy;
};

