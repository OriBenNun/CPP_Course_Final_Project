#pragma once
#include "Node.h"

class Edge
{
public:
    node* from;
    node* to;
    int weight;

    explicit Edge(node* from, node* to, int weight) : from(from), to(to), weight(weight) {}
};
