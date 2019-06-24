#include "Machine.h"


Machine::Machine(std::string filename_texture, Item in, Item out, float energy) :
	m_position(sf::Vector2f(0, 0)),
	m_itemIn(in),
	m_itemOut(out),
	m_energy(energy)
{
	if (!m_texture.loadFromFile(filename_texture))
		std::cout << "Fail to load machine texture" << std::endl;
}

Machine::~Machine()
{
}

std::ostream& operator<<(std::ostream& out, Machine& m)
{
	out << "IN:" << itemToString(m.m_itemIn) << "|OUT:" << itemToString(m.m_itemOut) << "|ENERGY:" << m.m_energy;
	return out;
}

Item stringToItem(std::string str_item)
{
	Item item = null;

	if (str_item == "iron_ore")
		item = iron_ore;
	else if (str_item == "copper_ore")
		item = copper_ore;

	return item;
}

std::string itemToString(Item item)
{
	std::string str = "";

	switch (item)
	{
	case Item::null:
		str = "null";
		break;
	case Item::iron_ore:
		str = "iron_ore";
		break;
	case Item::copper_ore:
		str = "copper_ore";
		break;
	}

	return str;
}
