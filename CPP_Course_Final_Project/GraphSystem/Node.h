#pragma once
#include <map>
#include <string>

class node
{
public:
    std::string name;

    explicit node(std::string name) : name(std::move(name))
    {
    }

    void add_edge(const node& to_node, float weight)
    {
        edges_.insert(std::pair<std::string, float>(to_node.name, weight));
    }

    std::map<std::string, float> get_edges() const
    {
        return edges_;
    }

private:
    std::map<std::string, float> edges_ = std::map<std::string, float>();
};
