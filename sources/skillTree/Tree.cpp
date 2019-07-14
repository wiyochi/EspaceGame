#include "Tree.hpp"

Tree::Tree()
{
}

Tree::~Tree()
{
    for(const auto skill : m_tree)
        delete skill;
}

Node* Tree::addSkill(std::string name, std::string description)
{
    m_tree.push_back(new Node(name, description));
    return m_tree[m_tree.size() - 1];
}

Node* Tree::operator[](std::string name)
{
    size_t i = 0;
    while(i < m_tree.size() && m_tree[i]->getName() != name)
        i++;
    
    return (i < m_tree.size() ? m_tree[i] : nullptr);
}

std::ostream& operator<<(std::ostream& out, Tree& t)
{
    for(const auto node : t.m_tree)
        out << *node;
    return out;
}