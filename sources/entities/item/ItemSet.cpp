#include "ItemSet.hpp"

ItemSet::ItemSet(std::vector<std::vector<Item*>>& items, std::vector<std::vector<int>>& quantity)
{
    for(unsigned int i = 0; i < items.size(); i++)
    {
        std::vector<ItemQuantity*> vec;
        for(unsigned int j = 0; j < items[i].size(); j++)
        {
            ItemQuantity* n = new ItemQuantity;
            n->item = items[i][j];
            n->quantity = quantity[i][j];
            vec.push_back(n);
        }
        m_set.push_back(vec);
    }
}

ItemSet::~ItemSet()
{
}

std::vector<std::vector<ItemQuantity*>>& ItemSet::getSet()
{
    return m_set;
}

std::vector<std::vector<ItemQuantity*>> ItemSet::getCopySet()
{
    return m_set;
}

std::ostream& operator<<(std::ostream& out, ItemSet& s)
{
	out << "[";
	for (unsigned int i = 0; i < s.m_set.size(); i++)
    {
        for(unsigned int j = 0; j < s.m_set[i].size(); j++)
        {
            out << "(\"" << s.m_set[i][j]->item->getName() << "\"," << s.m_set[i][j]->quantity << ")";
        }
        if(i+1 < s.m_set[i].size())
            out << " | ";
    }
	out << "]";
	return out;
}