#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Item.h"

class Machine : public sf::Drawable
{
public:
	Machine(std::string filename_texture, Item in, Item out, float energy);
	~Machine();
	std::vector<sf::Vector2i>& getShape();
	void setPosition(sf::Vector2i newPos);
	sf::Vector2i getPosition();

	friend std::ostream& operator<<(std::ostream& out, Machine& m);

private:
	sf::Texture					m_texture;
	sf::Vector2i				m_position;
	Item						m_itemIn;
	Item						m_itemOut;
	float						m_energy;
	std::vector<sf::Vector2i>	m_shape;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

