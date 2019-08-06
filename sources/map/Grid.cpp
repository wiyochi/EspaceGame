#include "Grid.hpp"

Grid::Grid(int width, int height, sf::Vector2f offset, sf::Vector2f squareSize) :
	m_width(width),
	m_height(height),
	m_offset(offset),
	m_squareSize(squareSize),
	m_leftClickPressed(false)
{
	for (int i = 0; i < (m_width + 1); i++)
	{
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(m_offset.x + i * m_squareSize.x, m_offset.y), sf::Color::Blue));
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(m_offset.x + i * m_squareSize.x, m_offset.y + m_height * m_squareSize.y), sf::Color::Blue));
	}
	for (int i = 0; i < (m_height + 1); i++)
	{
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(m_offset.x, m_offset.y + i * m_squareSize.y), sf::Color::Blue));
		m_pointStrips.push_back(sf::Vertex(sf::Vector2f(m_offset.x + m_width * m_squareSize.x, m_offset.y + i * m_squareSize.y), sf::Color::Blue));
	}
}

Grid::~Grid()
{
	for(auto machine : m_machines)
	{
		delete machine;
	}
}

std::string Grid::getName()
{
	return m_name;
}

void Grid::setName(std::string name)
{
	m_name = name;
}

// TODO: faire les v�rif n�cessaires
void Grid::addMachine(Machine* machine)
{
	m_machines.push_back(machine);
	m_cases.push_back(std::vector<sf::RectangleShape>());
	std::vector<sf::Vector2i> machineShape = machine->getShape();
	sf::Vector2i pos = machine->getPosition();

	for (size_t i = 0; i < machineShape.size(); i++)
	{
		m_cases.back().push_back(sf::RectangleShape(m_squareSize));
		m_cases.back().back().setPosition(sf::Vector2f(m_offset.x + (pos.x + machineShape[i].x) * m_squareSize.x, m_offset.y + (pos.y + machineShape[i].y) * m_squareSize.y));
		m_cases.back().back().setFillColor(sf::Color::Red);
	}
}

std::vector<Machine*>& Grid::getMachines()
{
	return m_machines;
}

void Grid::update(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_cases.size(); i++)
	{
		for (auto& rec : m_cases[i])
		{
			if (!m_leftClickPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && rec.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				m_leftClickPressed = true;
				std::cout << "[" << m_name << "][" << i << "]" << *m_machines[i] << std::endl;
				m_machines[i]->switchDrawTree();
			}
			else if (m_leftClickPressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_leftClickPressed = false;
			}
		}
	}
}


void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& machine : m_machines)
		target.draw(*machine, states);
	for (auto& cases : m_cases)
		for (auto& square : cases)
			target.draw(square, states);
	target.draw(&m_pointStrips[0], m_pointStrips.size(), sf::Lines);
}
