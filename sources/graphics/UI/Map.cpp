#include "Map.hpp"

Map::Map(int id, sf::RenderWindow & window):_x(id * MAP_WIDTH * CASE_WIDTH), _y(0), _window(window)
{
    _map_view = sf::View(sf::FloatRect(id * MAP_WIDTH * CASE_WIDTH + MAP_OFFSET, 0, MAP_WIDTH * CASE_WIDTH, MAP_HEIGHT * CASE_HEIGHT));
    _map_view.setViewport(sf::FloatRect(0, 0, 9.0/16.0, 1));
    for (int x = 0; x < MAP_WIDTH; ++x)
    {
        for (int y = 0; y < MAP_HEIGHT; ++y)
        {
            cases.push_back(Case( x * CASE_WIDTH + _x, y * CASE_HEIGHT + _y, (id == 2) ? "DIRT" : "STONE"));
        }
    }
}


void Map::draw() const
{
	for (auto r : cases)
		_window.draw(r);
}

void Map::activeView()
{
    _window.setView(_map_view);
}
