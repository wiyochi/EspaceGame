#include "Grid.h"

Grid::Grid(int width, int height, sf::Vector2f squareSize) :
	m_width(width),
	m_height(height),
	m_squareSize(squareSize)
{
	for (int i = 0; i < (m_width + 1); i++)
	{
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(i * m_squareSize.x, 0.f), sf::Color::Blue));
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(i * m_squareSize.x, m_height * m_squareSize.y), sf::Color::Blue));
	}
	for (int i = 0; i < (m_height + 1); i++)
	{
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(0.f, i * m_squareSize.y), sf::Color::Blue));
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(m_width * m_squareSize.x, i * m_squareSize.y), sf::Color::Blue));
	}
}

Grid::~Grid()
{
}

// TODO: faire les vérif nécessaires
void Grid::addMachine(Machine* machine)
{
	m_machines.push_back(machine);
	std::vector<sf::Vector2i> machineShape = machine->getShape();
	sf::Vector2i pos = machine->getPosition();

	for (unsigned int i = 0; i < machineShape.size(); i++)
	{
		m_cases.push_back(sf::RectangleShape(m_squareSize));
		m_cases[m_cases.size() - 1].setPosition(sf::Vector2f((pos.x + machineShape[i].x) * m_squareSize.x, (pos.y + machineShape[i].y) * m_squareSize.y));
		m_cases[m_cases.size() - 1].setFillColor(sf::Color::Red);
	}
}


void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto square : m_cases)
		target.draw(square, states);
	target.draw(&m_pointStrips[0], m_pointStrips.size(), sf::Lines);
}
