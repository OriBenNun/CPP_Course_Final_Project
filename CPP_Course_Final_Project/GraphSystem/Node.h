#pragma once
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include "Edge.h"

class Edge;

class node
{
public:
    std::string name;

    explicit node(std::string name) : name(std::move(name))
    {
        edges_ = new std::vector<Edge>();
    }

    void add_edge_and_order(const Edge& new_edge)
    {
        edges_.push_back(new_edge);
        std::sort(edges_->begin(), edges_->end(), []( Edge* a, const Edge& b) { return a->weight < b.weight; });
    }

    std::vector<Edge>* get_edges() const
    {
        return edges_;
    }

private:
    std::vector<Edge>* edges_;
};
