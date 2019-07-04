#include "ItemSet.hpp"

ItemSet::ItemSet(std::vector<Item*> items)
{
    m_set.push_back(items);
}

ItemSet::ItemSet(std::vector<std::vector<Item*>>& set) :
    m_set(set)
{
}

ItemSet::~ItemSet()
{
}

std::vector<std::vector<Item*>>& ItemSet::getSet()
{
    return m_set;
}

std::vector<std::vector<Item*>> ItemSet::getCopySet()
{
    return m_set;
}

void ItemSet::addItems(std::vector<Item*> items)
{
    m_set.push_back(items);
}

bool ItemSet::operator==(ItemSet& itemSet)
{
    std::vector<std::vector<Item*>> set1 = getCopySet();
    std::vector<std::vector<Item*>> set2 = itemSet.getCopySet();

    return set1.size() == 0 && set1.size() == set2.size();
}