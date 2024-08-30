#pragma once
#include <string>

#include "Node.h"

class edge
{
public:
    edge(node* from, node* to, float weight) : from(from), to(to), weight(weight){}

private:
    float weight;
    node* from;
    node* to;
};
