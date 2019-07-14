#include "Node.hpp"

NeededNode::NeededNode(Node* n, int nQ) :
    node(n),
    actualQuantity(0),
    neededQuantity(nQ)
{
}


Node::Node(std::string name, std::string description) :
    m_name(name),
    m_description(description),
    m_quantity(0)
{
}

Node::~Node()
{
    for (const auto nn : m_need)
        delete nn;
}

std::string Node::getName()
{
    return m_name;
}

void Node::addNeededNode(Node* node, int neededQuantity)
{
    if(node)
    {
        node->addChild(this);
        NeededNode* n = new NeededNode(node, neededQuantity);
        m_need.push_back(n);
    }
}

void Node::addChild(Node* node)
{
    m_children.push_back(node);
}

void Node::increaseNeeded(Node* node)
{
    size_t i = 0;
    while(i < m_need.size() && m_need[i]->node != node)
        i++;

    if(m_need[i]->node == node)
    {
        m_need[i]->actualQuantity = (m_need[i]->actualQuantity >= m_need[i]->neededQuantity ? m_need[i]->neededQuantity : m_need[i]->actualQuantity + 1);
    }
}

void Node::increase()
{
    bool ok = true;
    for (const auto nn : m_need)
        ok = ok && nn->actualQuantity >= nn->neededQuantity;
    
    if(ok)
    {
        m_quantity += 1;
        for(const auto child : m_children)
        {
            child->increaseNeeded(this);
        }
    }
}

std::ostream& operator<<(std::ostream& out, Node& node)
{
    out << "Node " << node.m_name << ": " << std::endl;
    out << "Description: " << node.m_description << std::endl;
    out << "Quantity: " << node.m_quantity << std::endl;
    for (const auto nn : node.m_need)
        out << "  " << nn->node->m_name << ": (" << nn->neededQuantity << "," << nn->actualQuantity << ")" << std::endl;
    return out;
}