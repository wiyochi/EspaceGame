#include "Map.hpp"

Map::Map(int id, sf::RenderWindow & window):_x(id * MAP_WIDTH + MAP_OFFSET), _y(id * MAP_HEIGHT + MAP_OFFSET), _window(window)
{
    _map_view = sf::View(sf::FloatRect(id * MAP_WIDTH + MAP_OFFSET, id * MAP_HEIGHT + MAP_OFFSET, MAP_WIDTH, MAP_HEIGHT));
    
    for (int x = 0; x < MAP_WIDTH; ++x)
        for (int y = 0; y < MAP_HEIGHT; ++y)
            cases[x][y] = new Case(window, x + id * MAP_WIDTH + MAP_OFFSET, y + id * MAP_HEIGHT + MAP_OFFSET);
}


void Map::draw() const
{
    for (int x = 0; x < MAP_WIDTH; ++x)
        for (int y = 0; y < MAP_HEIGHT; ++y)
            cases[x][y]->draw();
}

void Map::activeView()
{
    _window.setView(_map_view);
}
