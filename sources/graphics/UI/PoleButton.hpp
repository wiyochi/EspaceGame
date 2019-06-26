#ifndef __POLE_BUTTON_HPP__
#define __POLE_BUTTON_HPP__

#include "Button.hpp"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

const int x[] = {0, 640, 0, 640};
const int y[] = {0, 0, 360, 360};

class PoleButton {
private:
    Button _button;
public:
    PoleButton(int id);
    void draw(sf::RenderWindow & window) const;
    void move(float, float);
    
};






#endif
