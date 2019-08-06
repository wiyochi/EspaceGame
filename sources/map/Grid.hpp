#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../machine/Machine.hpp"

class Grid : public sf::Drawable
{
public:
	Grid(int width, int height, sf::Vector2f offset,sf::Vector2f squareSize);
	~Grid();
	std::string				getName		();
	void					setName		(std::string name);
	void 					addMachine	(Machine* machine);
	std::vector<Machine*>& 	getMachines	();
	void					update		(sf::RenderWindow& window);

private:
	std::string										m_name;
	int 											m_width;
	int 											m_height;
	sf::Vector2f									m_offset;
	sf::Vector2f 									m_squareSize;
	std::vector<sf::Vertex> 						m_pointStrips;
	std::vector<std::vector<sf::RectangleShape>>	m_cases;
	std::vector<Machine*>							m_machines;
	bool											m_leftClickPressed;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

