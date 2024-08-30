#pragma once
#include <map>
#include <string>

#include "Edge.h"

class node
{
public:
    std::string name;

    explicit node(std::string name) : name(std::move(name))
    {
    }
    
    void add_edge(const edge& new_edge)
    {
        edges_.push_back(new_edge);
    }

    std::vector<edge> get_edges() const
    {
        return edges_;
    }

private:
    std::vector<edge> edges_;
};
