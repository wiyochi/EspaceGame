#include "Map.hpp"

Map::Map(int id, sf::RenderWindow &window) :
		_x((id + 1) * MAP_WIDTH * CASE_WIDTH * 3), _y(0), _window(window) {
	/*
	 * Les poles sont déssinés à partir des points suivants :
	 * 	- (0 + 1) * MAP_WIDTH * CASE_WIDTH * 3 = 1 * 100 * 32 * 3 =  9600
	 * 	- (1 + 1) * MAP_WIDTH * CASE_WIDTH * 3 = 2 * 100 * 32 * 3 = 19200
	 * 	- (2 + 1) * MAP_WIDTH * CASE_WIDTH * 3 = 3 * 100 * 32 * 3 = 28800
	 * 	- (3 + 1) * MAP_WIDTH * CASE_WIDTH * 3 = 4 * 100 * 32 * 3 = 38400
	 *
	 * Ils sont déssinés sur un carré de taille MAP_WIDTH * CASE_WIDTH par MAP_HEIGHT * CASE_HEIGHT c'est à dire 3200x3200
	 */

	std::string test[4] = { "DIRT", "STONE", "GRASS", "WATER" };

	_map_view = sf::View(sf::FloatRect(id * MAP_WIDTH * CASE_WIDTH + MAP_OFFSET, 0, MAP_WIDTH * CASE_WIDTH, MAP_HEIGHT * CASE_HEIGHT));
	_map_view.setViewport(sf::FloatRect(0, 0, 9.0 / 16.0, 1));
	for (int x = 0; x < MAP_WIDTH; ++x) {
		for (int y = 0; y < MAP_HEIGHT; ++y) {
			cases.push_back(Case(x * CASE_WIDTH + _x, y * CASE_HEIGHT + _y, test[id]));
		}
	}
}

void Map::draw() const {
	for (auto r : cases)
		_window.draw(r);
}

void Map::activeView() {
	_window.setView(_map_view);
}
