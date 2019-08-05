#ifndef __CASE_HPP__
#define __CASE_HPP__

#include <string>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include "../utils/TextureManager.hpp"

const int CASE_WIDTH = 32;
const int CASE_HEIGHT = 32;

class Case: public sf::Drawable {
private:
	int _x;
	int _y;
	std::string _id;
	sf::Color getColor() const;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Case(int x, int y, std::string id);
	std::string getId() const;
};

#endif
