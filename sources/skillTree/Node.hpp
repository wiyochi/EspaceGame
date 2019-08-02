#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

constexpr auto FONT_NODE_PATH = R"(resources/fonts/Roboto-Thin.ttf)";

class Node;

struct NeededNode
{
    NeededNode(Node* n, int nQ);

    Node*       node;
    int         actualQuantity;
    const int   neededQuantity;
};

class Node : public sf::Drawable
{
public:
    Node(std::string name, std::string description);
    ~Node();
    std::string					getName         ();
    void						addNeededNode   (Node* node, int neededQuantity);
    void						increase        ();

	// ### Pour l'affichage de débug
    void						setRadius       (float r);
    void						setPosition     (sf::Vector2f pos);
    bool						isIn            (sf::Vector2f point);
    bool						update          (sf::RenderWindow& window);
	const std::vector<Node*>&	getChildren		();
	sf::Vector2f				getPosition		();
	// ###

    friend std::ostream& operator<<(std::ostream& out, Node& node);

private:
    void        addChild        (Node* node, int neededQuantity);
    void        increaseNeeded  (Node* node);
    
    std::string                 m_name;
    std::string                 m_description;
    int                         m_quantity;
    std::vector<Node*>          m_children;
    std::vector<NeededNode*>    m_need;

	// ### Pour l'affichage de débug
    sf::CircleShape             m_shape;
	bool                        m_rightClickPressed;
	bool						m_dragAndDropOn;
	static bool					static_dragAndDropOn;
	sf::Font					m_font;
	sf::Text					m_text;
	std::vector<sf::Text>		m_numbers;
	std::vector<sf::Vertex*>	m_links;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// ###
};
