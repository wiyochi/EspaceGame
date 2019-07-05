#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "item/Item.hpp"
#include "item/ItemSet.hpp"

class Machine : public sf::Drawable
{
public:
	Machine(std::string filename_texture, float energy);
	~Machine();
	std::vector<sf::Vector2i>& 	getShape	();
	void 						setPosition	(sf::Vector2i newPos);
	sf::Vector2i 				getPosition	();
	void						setIn		(ItemSet* set);
	void						setOut		(ItemSet* set);

	friend std::ostream& operator<<(std::ostream& out, Machine& m);

private:
	sf::Texture					m_texture;
	sf::Vector2i				m_position;
	ItemSet*					m_setIn;
	ItemSet*					m_setOut;
	float						m_energy;
	std::vector<sf::Vector2i>	m_shape;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

