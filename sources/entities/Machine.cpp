#include "Machine.h"

Machine::Machine(std::string filename_texture, Item in, Item out, float energy) :
	m_position(sf::Vector2i(0, 0)),
	m_itemIn(in),
	m_itemOut(out),
	m_energy(energy),
	m_shape(sf::LinesStrip)
{
	if (!m_texture.loadFromFile(filename_texture))
		std::cout << "Fail to load machine texture" << std::endl;
}

Machine::~Machine()
{
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

std::ostream& operator<<(std::ostream& out, Machine& m)
{
	out << "in:" << itemToString(m.m_itemIn) << "|out:" << itemToString(m.m_itemOut) << "|energy:" << m.m_energy << "|shape:[";
	for (size_t i = 0; i < m.m_shape.size(); i++)
		out << "[" << m.m_shape[i].x << "," << m.m_shape[i].y << "]";
	out << "]";
	return out;
}

void Machine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}