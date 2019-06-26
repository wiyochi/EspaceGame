#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Item.h"

class Machine : public sf::Drawable
{
public:
	Machine(std::string filename_texture, Item in, Item out, float energy);
	~Machine();
	sf::VertexArray& getShape();

	friend std::ostream& operator<<(std::ostream& out, Machine& m);

private:
	sf::Texture		m_texture;
	sf::Vector2f	m_position;
	Item			m_itemIn;
	Item			m_itemOut;
	float			m_energy;
	sf::VertexArray	m_shape;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

