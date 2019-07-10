#include "Machine.hpp"

Machine::Machine(std::string filename_texture, float energy) :
	m_position(sf::Vector2i(0, 0)),
	m_setIn(nullptr),
	m_setOut(nullptr),
	m_energy(energy)
{
	if (!m_texture.loadFromFile(filename_texture))
		std::cout << "Fail to load machine texture" << std::endl;
}

Machine::~Machine()
{
	delete m_setIn;
	delete m_setOut;
}

std::string Machine::getName()
{
	return m_name;
}

void Machine::setName(std::string name)
{
	m_name = name;
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
}