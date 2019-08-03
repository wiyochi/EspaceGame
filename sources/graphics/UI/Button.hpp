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
protected:
	sf::RectangleShape _shape;
	sf::RenderWindow &_window;
public:

	Button(sf::RenderWindow &window, std::string fontName, sf::String text, sf::Vector2f size);
	virtual void draw();
	void move(float offsetX, float offsetY);
	void addText(std::string text);
	std::string getText();
	bool contains(float x, float y);
	virtual void action();
};

#endif
