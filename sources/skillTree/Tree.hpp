#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Node.hpp"

/*  Exemple d'utilisation:
Trois skill:
 - "sediment" de niveau 1 ne demandant aucun autre skill
 - "miningDepth" de niveau 1 ne demandant aucun autre skill
 - "crushing" de niveau 2 demandant 2 points dans "sediment" et 3 points dans "miningDepth"

// Creation de l'arbre
Tree* t = new Tree();

// Ajout des 3 skills (noms et descriptions)
t->addSkill("sediment", "description de sediment");
t->addSkill("miningDepth", "description de miningDepth");
t->addSkill("crushing", "description de crushing");

// Ajout des skills demandés par "crushing" avec pointeur sur les skills + la quantité de points demandés
(*t)["crushing"]->addNeededNode((*t)["sediment"], 2);
(*t)["crushing"]->addNeededNode((*t)["miningDepth"], 3);

// Incrementation des skills
(*t)["sediment"]->increase();
(*t)["miningDepth"]->increase();
(*t)["miningDepth"]->increase();
(*t)["miningDepth"]->increase();
(*t)["miningDepth"]->increase();

(*t)["crushing"]->increase(); // -> ne fonctionne pas puisqu'il manque 1 point dans "sediment"

(*t)["sediment"]->increase();
(*t)["crushing"]->increase();
*/

class Tree : public sf::Drawable
{
public:
    Tree();
    ~Tree();
    Node*   addSkill    (std::string name, std::string description);

	// ### Pour l'affichage de débug
    void    setPosition (sf::Vector2f pos);
    void    update      (sf::RenderWindow& window);
	void	initLinks	();
	// ###

    Node* operator[](std::string name);
    friend std::ostream& operator<<(std::ostream& out, Tree& t);

private:
    std::vector<Node*>		m_tree;

	// ### Pour l'affichage de débug
    sf::Vector2f			m_origin;
	std::vector<sf::Vertex>	m_links;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// ###
};