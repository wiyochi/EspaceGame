#pragma once
#include <vector>
#include "Item.hpp"

struct ItemQuantity
{
    Item*   item;
    int     quantity;
};

class ItemSet
{
public:
    ItemSet(std::vector<std::vector<Item*>>& items, std::vector<std::vector<int>>& quantity);
    ~ItemSet();
    std::vector<std::vector<ItemQuantity*>>& getSet();
    std::vector<std::vector<ItemQuantity*>> getCopySet();

	friend std::ostream& operator<<(std::ostream& out, ItemSet& s);

private:
    std::vector<std::vector<ItemQuantity*>> m_set;
};