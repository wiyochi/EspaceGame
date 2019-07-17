#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

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
    Node                        (std::string name, std::string description);
    ~Node                       ();
    std::string getName         ();
    void        addNeededNode   (Node* node, int neededQuantity);
    void        increase        ();
    void        setRadius       (float r);
    void        setPosition     (sf::Vector2f& pos);
    bool        isIn            (sf::Vector2f point);
    void        update          (sf::RenderWindow& window);

    friend std::ostream& operator<<(std::ostream& out, Node& node);

private:
    void        addChild        (Node* node);
    void        increaseNeeded  (Node* node);
    void        draw            (sf::RenderTarget& target, sf::RenderStates states) const;
    
    std::string                 m_name;
    std::string                 m_description;
    int                         m_quantity;
    std::vector<Node*>          m_children;
    std::vector<NeededNode*>    m_need;

    sf::CircleShape             m_shape;
    std::vector<sf::Vertex>     m_childrenLink;
    bool                        m_stop;
};
