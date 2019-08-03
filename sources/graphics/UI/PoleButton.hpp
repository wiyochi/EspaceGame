#ifndef __POLE_BUTTON_HPP__
#define __POLE_BUTTON_HPP__

#include "Button.hpp"
#include <string>
#include <iostream>
#include "Map.hpp"
#include <SFML/Graphics.hpp>

const int x[] = { 0, 640, 0, 640 };
const int y[] = { 0, 0, 360, 360 };

class PoleButton: public Button {
private:
	Map _map;
public:
	PoleButton(int id, sf::RenderWindow &window);
	virtual void action();
	virtual void draw();
};

#endif
