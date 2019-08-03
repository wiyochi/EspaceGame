#include "PoleButton.hpp"

PoleButton::PoleButton(int id, sf::RenderWindow &window) :
		Button(window, "resources/fonts/Roboto-Thin.ttf", L"Pôle ", sf::Vector2f(640, 360)), _map(id, window) {
	move(x[id], y[id]);

	std::cout << std::to_string(id) << std::endl;
	addText(std::to_string(id));
}

void PoleButton::draw() {
	//Button::draw();
	_map.draw();
}

void PoleButton::action() {
	std::cout << "Click redef" << std::endl;
	_map.activeView();
}
