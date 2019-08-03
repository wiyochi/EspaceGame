#include "Case.hpp"

Case::Case(int x, int y, std::string id) :
		_x(x), _y(y), _id(id) {
}

sf::Color Case::getColor() const {
	return (_id == "DIRT") ? sf::Color::Red : (_id == "STONE") ? sf::Color::White : (_id == "GRASS") ? sf::Color::Yellow : sf::Color::Blue;
}

void Case::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	sf::Vertex square[4];
	states.texture = getTexture(_id);
	square[0] = sf::Vertex(sf::Vector2f(_x, _y), getColor(),  sf::Vector2f(0, 0));
	square[1] = sf::Vertex(sf::Vector2f(_x + CASE_WIDTH, _y), getColor(), sf::Vector2f(32, 0));
	square[2] = sf::Vertex(sf::Vector2f(_x + CASE_WIDTH, _y + CASE_HEIGHT), getColor(), sf::Vector2f(32, 32));
	square[3] = sf::Vertex(sf::Vector2f(_x, _y + CASE_HEIGHT), getColor(), sf::Vector2f(0, 32));

	target.draw(square, 4, sf::Quads, states);
}

std::string Case::getId() const {
	return _id;
}
