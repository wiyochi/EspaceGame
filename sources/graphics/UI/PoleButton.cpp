#include "PoleButton.hpp"

PoleButton::PoleButton(int id) : Button("resources/fonts/Roboto-Thin.ttf", L"Pôle ", sf::Vector2f(640, 360))
{
    move(x[id], y[id]);
    
    std::cout << std::to_string(id) << std::endl;
    addText(std::to_string(id));
}



void PoleButton::draw(sf::RenderWindow & window) const
{
    Button::draw(window);
}


void PoleButton::action()
{
    std::cout << "Click redef" << std::endl;
}
