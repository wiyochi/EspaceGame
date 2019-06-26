#pragma once
#include <string>

/*   Enum Item
 * Contient actuellement tous les items cr��s et utilis�s par les machines
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