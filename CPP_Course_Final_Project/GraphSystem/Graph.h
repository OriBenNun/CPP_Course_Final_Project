#pragma once
#include <iostream>
#include <vector>
#include <xstring>

#include "Node.h"

class graph
{
public:
    explicit graph(const std::vector<std::vector<std::string>>& parsed_data)
    {
        if (!try_populate_graph(parsed_data))
        {
            std::cout << "Data is not valid for a graph. Aborting." << '\n';
            throw std::runtime_error("Data is not valid for a graph. Aborting.");
        }
    }

    void print_graph() const;

private:
    bool try_populate_graph(const std::vector<std::vector<std::string>>& parsed_data);
    void addNode(const std::string& node_name);
    void addEdge(const std::string& node1, const std::string& node2, float weight);
    std::unordered_map<std::string, float> getNeighbors(const std::string& node);

    std::unordered_map<std::string, Node*> nodes;

};
