#include "Button.hpp"
Button::Button(sf::RenderWindow &window, std::string fontName, sf::String text, sf::Vector2f size) :
		_shape(size), _window(window) {
	if (!_font.loadFromFile(fontName)) {
		std::cout << "Erreur chargement police : " << fontName << std::endl;
	} else {
		_text.setFont(_font);
		_text.setString(text);
		_text.setFillColor(sf::Color::Red);
	}

	_shape.setFillColor(sf::Color::Blue);
}

void Button::draw() {
	_window.draw(_shape);
	_window.draw(_text);
}

void Button::move(float offsetX, float offsetY) {
	_text.move(offsetX, offsetY);
	_shape.move(offsetX, offsetY);
}

void Button::addText(std::string text) {
	_text.setString(_text.getString() + text);
}

std::string Button::getText() {
	return _text.getString();
}

bool Button::contains(float x, float y) {
	return _shape.getGlobalBounds().contains(x, y);
}

void Button::action() {
	std::cout << "Click : " << getText() << std::endl;
}
