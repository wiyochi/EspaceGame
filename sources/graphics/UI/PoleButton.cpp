#include "PoleButton.hpp"

PoleButton::PoleButton(int id, sf::RenderWindow &window) :
		Button(window, "resources/fonts/Roboto-Thin.ttf", L"Pôle ", sf::Vector2f(640, 360)), _map(id, window) {
	move(x[id], y[id]);

	addText(std::to_string(id));
}

void PoleButton::draw() {
	_map.draw();
	_window.setView(sf::View(sf::FloatRect(0, 0, 1280, 720)));
}

void PoleButton::action() {
	std::cout << "Click redef" << std::endl;
}

void PoleButton::setMapMode(int mode) {
	_map.setMode(mode);
}
