#include "Button.hpp"

Button::Button(std::string fontName, sf::String text, sf::Vector2f size) : _shape(size)
{
    if (!_font.loadFromFile(fontName))
    {
        std::cout << "Erreur chargement police : " << fontName << std::endl;
    } else
    {
        _text.setFont(_font);
        _text.setString(text);
        _text.setFillColor(sf::Color::Red);
        _buttons.push_back(*this);
    }
    
    _shape.setFillColor(sf::Color::Blue);
}

void Button::draw(sf::RenderWindow & window) const
{
    window.draw(_shape);
    window.draw(_text);
}

void Button::move(float offsetX, float offsetY)
{
    _text.move(offsetX, offsetY);
    _shape.move(offsetX, offsetY);
}

void Button::addText(std::string text)
{
    _text.setString(_text.getString() + text);
}
