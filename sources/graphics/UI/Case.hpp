#ifndef __CASE_HPP__
#define __CASE_HPP__

#include <string>
#include <iostream>
#include "Button.hpp"
#include <cstdlib>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>

const int CASE_WIDTH = 32;
const int CASE_HEIGHT = 32;

class Case : Button {
private:
    int _x;
    int _y;
    sf::Color _color;
    sf::Color getColor();
    const sf::Color getUniqColor();
public:
    Case(sf::RenderWindow & window, int x, int y);
    
    virtual void draw();
    
};

#endif
