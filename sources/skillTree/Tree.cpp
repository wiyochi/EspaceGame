#include "Tree.hpp"

Tree::Tree() :
    m_origin(sf::Vector2f(0.f, 0.f))
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
    sf::Vector2f pos = m_origin;
    pos.y += m_tree.size() * 30.f;
    m_tree[m_tree.size() - 1]->setPosition(pos);
    return m_tree[m_tree.size() - 1];
}

void Tree::setPosition(sf::Vector2f pos)
{
    m_origin = pos;
    for (size_t i = 0; i < m_tree.size(); i++)
    {
        sf::Vector2f position = m_origin;
		position.y += i * 50.f;
        m_tree[i]->setPosition(position);
    }
}

void Tree::update(sf::RenderWindow& window)
{
	for (const auto skill : m_tree)
	{
		if (skill->update(window))
		{
			initLinks();
		}

	}
}

void Tree::initLinks()
{
	/*m_links.clear();
	for (const auto skill : m_tree)
	{
		const std::vector<Node*>& children = skill->getChildren();
		for (const auto child : children)
		{
			m_links.push_back(skill->getPosition());
			m_links.push_back(sf::Vertex(child->getPosition(), sf::Color::Red));
		}
	}
	*/
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
        out << *node << std::endl;
    return out;
}

void Tree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//if(m_links.size() > 0)
	//	target.draw(&m_links[0], m_links.size(), sf::Lines, states);
    for(const auto node : m_tree)
        target.draw(*node, states);
}