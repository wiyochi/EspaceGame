#include "Node.hpp"

NeededNode::NeededNode(Node* n, int nQ) :
    node(n),
    actualQuantity(0),
    neededQuantity(nQ)
{
}


bool Node::static_dragAndDropOn = false;

Node::Node(std::string name, std::string description) :
    m_name(name),
    m_description(description),
    m_quantity(0),
	m_rightClickPressed(false),
	m_dragAndDropOn(false)
{
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setOutlineColor(sf::Color::White);
    m_shape.setRadius(20.f);

	if (m_font.loadFromFile(FONT_NODE_PATH))
	{
		m_text.setFont(m_font);
		m_text.setFillColor(sf::Color::White);
		m_text.setString(name);
		m_text.setStyle(sf::Text::Bold);
		m_text.setCharacterSize(15);
	}
	else
	{
		std::cout << "Error to load font for node" << std::endl;
	}
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


void Node::setRadius(float r)
{
    m_shape.setRadius(r);
}

void Node::setPosition(sf::Vector2f pos)
{
	m_shape.setPosition(pos - sf::Vector2f(m_shape.getRadius(), m_shape.getRadius()));
	m_text.setPosition(pos - sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));
}

bool Node::isIn(sf::Vector2f point)
{
    return m_shape.getGlobalBounds().contains(point);
}

bool Node::update(sf::RenderWindow& window)
{
    if(isIn(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
	{
        m_shape.setOutlineThickness(2);

		// Right click to increase and print into console
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && !m_rightClickPressed)
        {
            increase();
			std::cout << *this << std::endl;
			m_rightClickPressed = true;
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
			m_rightClickPressed = false;
        }
        
		// Left click to drag and drop
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !static_dragAndDropOn)
		{
			static_dragAndDropOn = true;
			m_dragAndDropOn = true;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			static_dragAndDropOn = false;
			m_dragAndDropOn = false;
		}
    }
    else
    {
        m_shape.setOutlineThickness(0);
    }

	if (m_dragAndDropOn)
	{
		setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	}

	return m_dragAndDropOn;
}

const std::vector<Node*>& Node::getChildren()
{
	return m_children;
}

sf::Vector2f Node::getPosition()
{
	return m_shape.getPosition() + sf::Vector2f(m_shape.getRadius(), m_shape.getRadius());
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
	target.draw(m_text, states);
}

std::ostream& operator<<(std::ostream& out, Node& node)
{
    out << "Node " << node.m_name << "(" << &node << "): ";
    out << "Description[\"" << node.m_description << "\"]";
    out << "Quantity[" << node.m_quantity << "]";
    out << "NeededNode[";
    for (const auto nn : node.m_need)
        out << "(" << nn->node->m_name << "," << nn->neededQuantity << "," << nn->actualQuantity << ")";
    out << "]";
    return out;
}