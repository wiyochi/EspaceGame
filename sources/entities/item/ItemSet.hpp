#pragma once
#include <vector>
#include "Item.hpp"

class ItemSet
{
public:
    ItemSet(std::vector<Item*> items);
    ItemSet(std::vector<std::vector<Item*>>& set);
    ~ItemSet();
    void addItems(std::vector<Item*> items);
    std::vector<std::vector<Item*>>& getSet();
    std::vector<std::vector<Item*>> getCopySet();

    bool operator==(ItemSet& itemSet);

private:
    std::vector<std::vector<Item*>> m_set;
};