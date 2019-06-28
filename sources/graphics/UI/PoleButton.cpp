#include "PoleButton.hpp"

PoleButton::PoleButton(int id) : _button("resources/fonts/Roboto-Thin.ttf", L"Pôle ", sf::Vector2f(640, 360))
{
    _button.move(x[id], y[id]);
    
    std::cout << std::to_string(id) << std::endl;
    _button.addText(std::to_string(id));
}



void PoleButton::draw(sf::RenderWindow & window) const
{
    _button.draw(window);
}

void PoleButton::move(float offsetX, float offsetY)
{
    _button.move(offsetX, offsetY);
}
