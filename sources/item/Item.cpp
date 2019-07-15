#include "Item.hpp"

std::vector<Item*> Item::items;

Item* Item::findItem(std::string name)
{
	Item* item = NULL;
	unsigned int i = 0;
	while(i < items.size() && items[i]->getName() != name)
		i++;
	if(i < items.size())
		item = items[i];
	return item;
}

void Item::deleteItems()
{
	for(auto item : items)
	{
		delete item;
	}
}

Item::Item(std::string name, std::string className, std::string textureFileName) :
	m_name(name),
	m_className(className)
{
	if (!m_texture.loadFromFile(textureFileName))
		std::cout << "Fail to load item texture" << std::endl;
	items.push_back(this);
}

Item::~Item()
{
}

std::string Item::getName()
{
	return m_name;
}

std::string Item::getClassName()
{
	return m_className;
}

std::ostream& operator<<(std::ostream& out, Item& i)
{
	out << "Item(" << &i << "): name[\"" << i.m_name << "\"]class[\"" << i.m_className << "\"]";
	return out;
}