#include "Case.hpp"

Case::Case(sf::RenderWindow & window, int x, int y): Button(window, "resources/fonts/Roboto-Thin.ttf", "", sf::Vector2f(CASE_WIDTH, CASE_HEIGHT)), _x(x), _y(y), _color(getUniqColor())
{
    _shape.setFillColor(getColor());
    _shape.move(_x,_y);
}


const sf::Color Case::getUniqColor()
{
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

sf::Color Case::getColor()
{
    return _color;
}

void Case::draw()
{
    _window.draw(_shape);
}


