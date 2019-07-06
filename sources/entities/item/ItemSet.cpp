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
    for (unsigned int i = 0; i < m_set.size(); i++)
    {
        for(unsigned int j = 0; j < m_set[i].size(); j++)
        {
            delete m_set[i][j];
        }
    }
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
        if(s.m_set[i].size() > 1) out << "(";
        for(unsigned int j = 0; j < s.m_set[i].size(); j++)
        {
            out << "(\"" << s.m_set[i][j]->item->getName() << "\"," << s.m_set[i][j]->quantity << ")";
        }
        if(s.m_set[i].size() > 1) out << ")";

        if(i < s.m_set.size() - 1)
            out << " | ";
    }
	out << "]";
	return out;
}