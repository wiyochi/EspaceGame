#include "Item.h"

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

Item::Item(std::string className, std::string name, std::string textureFileName) :
	m_name(name),
	m_class(className)
{
	if (!m_texture.loadFromFile(textureFileName))
		std::cout << "Fail to load item texture" << std::endl;
	items.push_back(this);
}

Item::~Item()
{
}

std::string Item::getClass() const
{
	return m_class;
}

std::string Item::getName() const
{
	return m_name;
}