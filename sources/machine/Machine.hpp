#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../item/Item.hpp"
#include "../item/ItemSet.hpp"
#include "../skillTree/Tree.hpp"

namespace Loader {
	Tree* loadSkillTree(std::string JSonFile);
}

class Machine : public sf::Drawable
{
public:
	Machine(std::string filename_texture, float energy);
	~Machine();
	std::string					getName		();
	void						setName		(std::string name);
	std::vector<sf::Vector2i>& 	getShape	();
	void 						setPosition	(sf::Vector2i newPos);
	sf::Vector2i 				getPosition	();
	void						setIn		(ItemSet* set);
	void						setOut		(ItemSet* set);
	void						switchDrawTree();

	friend std::ostream& operator<<(std::ostream& out, Machine& m);

private:
	std::string					m_name;
	sf::Texture					m_texture;
	sf::Vector2i				m_position;
	ItemSet*					m_setIn;
	ItemSet*					m_setOut;
	float						m_energy;
	std::vector<sf::Vector2i>	m_shape;
	Tree*						m_tree;
	bool						m_showTree;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

