#include "Item.h"

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
