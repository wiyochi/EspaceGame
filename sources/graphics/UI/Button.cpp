#include "Button.hpp"

Button::Button(std::string fontName, std::string text)
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
}

void Button::draw(sf::RenderWindow & window) const
{
    
}
