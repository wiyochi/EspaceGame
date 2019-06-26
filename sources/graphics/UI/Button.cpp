#include "Button.hpp"

Button::Button(std::string fontName, std::string text, sf::Vector2f size) : _shape(size)
{
    if (!_font.loadFromFile(fontName))
    {
        std::cout << "Erreur chargement police : " << fontName << std::endl;
    } else
    {
        _text.setFont(_font);
        _text.setString(text);
        _text.setFillColor(sf::Color::Red);
    }
    
    _shape.setFillColor(sf::Color::Blue);
}

void Button::draw(sf::RenderWindow & window) const
{
    window.draw(_shape);
    window.draw(_text);
}
