#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Button {
private:
    sf::Font _font;
    sf::Text _text;
    sf::RectangleShape _shape;
public:
    static std::vector<Button*> _buttons;
    
    Button(std::string fontName, sf::String text, sf::Vector2f size);
    void draw(sf::RenderWindow & window) const;
    void move(float offsetX, float offsetY);
    void addText(std::string text);
    std::string getText();
    bool contains(float x, float y);
};



#endif
