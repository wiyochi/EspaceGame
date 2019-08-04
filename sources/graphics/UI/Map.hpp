#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <string>
#include "Case.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

static const int MAP_OFFSET = 0x00FFFF;
static const int MAP_WIDTH = 100;
static const int MAP_HEIGHT = 100;

class Map {
private:
	int _x; // Coordonnées en haut à gauche du rendu.
	int _y; // Coordonnées en haut à gauche du rendu.
	int _mode; // Mode de rendu de la map.
	int _id; // Pole représenté par la map (de 0 à 3).
	sf::RenderWindow &_window; // Fenêtre.
	sf::View _map_view; // Vue utilisée pour le rendu du pôle.
	std::vector<Case> cases;
public:
	static const int NO_SCREEN = 0;
	static const int SPLITSCREEN = 1;
	static const int FULLSCREEN = 2;

	Map(int id, sf::RenderWindow &window);
	void draw() const;
	void setMode(int mode);
	void activeView();
};

#endif
