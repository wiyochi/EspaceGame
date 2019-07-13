#pragma once
#include <iostream>
#include <string>
#include <vector>

class Node;

struct NeededNode
{
    NeededNode(Node* n, int nQ);

    Node*       node;
    int         actualQuantity;
    const int   neededQuantity;
};


class Node
{
public:
    Node                        (std::string name, std::string description);
    ~Node                       ();
    std::string getName         ();
    void        addNeededNode   (Node* node, int neededQuantity);
    void        addChild        (Node* node);
    void        increaseNeeded  (Node* node);
    void        increase        ();

    friend std::ostream& operator<<(std::ostream& out, Node& node);

private:
    std::string                 m_name;
    std::string                 m_description;
    int                         m_quantity;
    std::vector<Node*>          m_children;
    std::vector<NeededNode*>    m_need;
};
