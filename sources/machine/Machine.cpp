#include "Machine.hpp"

Machine::Machine(std::string machineName, std::string filename_texture, float energy) :
	m_name(machineName),
	m_position(sf::Vector2i(0, 0)),
	m_setIn(nullptr),
	m_setOut(nullptr),
	m_energy(energy),
	m_showTree(false)
{
	if (!m_texture.loadFromFile(filename_texture))
		std::cout << "Fail to load machine texture" << std::endl;
	if(Loader::loadSkillTree(SKILL_TREE_PATH + m_name + SKILL_EXTENSION, &m_tree))
		m_tree->initLinks();
}

Machine::~Machine()
{
	delete m_setIn;
	delete m_setOut;
	delete m_tree;
}

std::string Machine::getName()
{
	return m_name;
}

std::vector<sf::Vector2i>& Machine::getShape()
{
	return m_shape;
}

void Machine::setPosition(sf::Vector2i newPos)
{
	m_position = newPos;
}

sf::Vector2i Machine::getPosition()
{
	return m_position;
}

void Machine::setIn(ItemSet* set)
{
	if(m_setIn != nullptr)
		delete m_setIn;
	m_setIn = set;
}

void Machine::setOut(ItemSet* set)
{
	if(m_setOut != nullptr)
		delete m_setOut;
	m_setOut = set;
}

void Machine::switchDrawTree()
{
	m_showTree = !m_showTree;
}

void Machine::update(sf::RenderWindow& window)
{
	if(m_tree)
		m_tree->update(window);
}

std::ostream& operator<<(std::ostream& out, Machine& m)
{
	out << "Machine(" << &m;
	out << "): in" << *(m.m_setIn);
	out << "out" << *(m.m_setOut);
	out << "energy[" << m.m_energy;
	out << "]shape[";
	for (size_t i = 0; i < m.m_shape.size(); i++)
		out << "[" << m.m_shape[i].x << "," << m.m_shape[i].y << "]";
	out << "]";
	return out;
}

void Machine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_showTree)
		target.draw(*m_tree, states);
}