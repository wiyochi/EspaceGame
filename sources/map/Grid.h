#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../entities/Machine.h"

class Grid : public sf::Drawable
{
public:
	Grid(int width, int height, sf::Vector2f squareSize);
	~Grid();
	void addMachine(Machine* machine);

private:
	int m_width;
	int m_height;
	sf::Vector2f m_squareSize;
	std::vector<sf::Vertex> m_pointStrips;
	std::vector<sf::RectangleShape> m_cases;
	std::vector<Machine*> m_machines;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

