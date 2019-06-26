#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::Font _font;
    sf::Text _text;
    /*sf::Shape _shape;*/
public:
    Button(std::string fontName, std::string text);
    void draw(sf::RenderWindow & window) const;
    
};






#endif
