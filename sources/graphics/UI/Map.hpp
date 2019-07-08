#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <string>
#include "Case.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>



static const int MAP_OFFSET = 0xFFFFFF;
static const int MAP_WIDTH = 100;
static const int MAP_HEIGHT = 100;
    
class Map {
private:
    int _x;
    int _y;
    sf::RenderWindow & _window;
    sf::View _map_view;
    Case * cases[MAP_WIDTH][MAP_HEIGHT];
public:
    Map(int id, sf::RenderWindow & window);
    virtual void draw() const;
    void activeView();
};

#endif
