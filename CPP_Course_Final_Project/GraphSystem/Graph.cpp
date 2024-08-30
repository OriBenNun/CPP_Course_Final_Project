#include "Graph.h"

#include <algorithm>
#include <string>
#include <unordered_map>

void graph::print_graph() const
{
    
}

// The data is valid if:
// 1. There is at least one valid line in the data
// 2. A valid line has at least 2 elements, in the following format:
// A, 1, B (1 is the weight of the edge between A and B)
// Here's an example for a few valid lines:
// A, 1, B
// A, 1,, B (redundant whitespace and empty elements is allowed)
// A, 3, C, 1.1, D
// A, 1.5, D, 2.5, E, 3.5, F, 0.5, H 
// A, 1, E, 2, F
// Here's an example for a few invalid lines:
// A, 1, A (can't have self-loops)
// A, 1, 1 
// 3, C, 1.1, D 
// A, 1.5, D, 2.5, E, 3.5, F, H 
// A, F
// A, 1, B, D
// A, 3, C, 1.1
/**
 * Tries to populate the graph with data from the given parsed_data vector.
 *
 * @param parsed_data a vector of vectors of strings representing the parsed data
 *
 * @return true if the graph was successfully populated, false otherwise
 *
 * @throws None
 */
bool graph::try_populate_graph(const std::vector<std::vector<std::string>>& parsed_data)
{
    for (const auto& line : parsed_data) {
        if (line.size() >= 3) {
            std::string node1 = line[0];
            std::string node2 = line[2];

            if (node1 != node2) {
                std::string weightStr = line[1];

                try {
                    float weight = std::stof(weightStr);
                    addNode(node1);
                    addNode(node2);
                    addEdge(node1, node2, weight);

                    for (size_t i = 3; i < line.size(); i += 2) {
                        std::string nextNode = line[i];
                        std::string nextWeightStr = line[i + 1];

                        if (nextNode.empty() || nextWeightStr.empty()) {
                            break; // Invalid format
                        }

                        try {
                            float nextWeight = std::stof(nextWeightStr);
                            addNode(nextNode);
                            addEdge(node2, nextNode, nextWeight);
                            node2 = nextNode;
                        } catch (const std::invalid_argument&) {
                            return false; // Invalid weight format
                        }
                    }
                } catch (const std::invalid_argument&) {
                    return false; // Invalid weight format
                }
            } else {
                return false; // Self-loop is not allowed
            }
        } else {
            return false; // Invalid line format
        }
    }
    
    return true;
}


void graph::addNode(const std::string& name) {
    if (nodes.find(name) == nodes.end()) {
        nodes[name] = new Node(name);
    }
}

void graph::addEdge(const std::string& node1, const std::string& node2, float weight) {
    if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
        nodes[node1]->neighbors[node2] = weight;
        nodes[node2]->neighbors[node1] = weight;
    }
}

std::unordered_map<std::string, float> graph::getNeighbors(const std::string& node) {
    if (nodes.find(node) != nodes.end()) {
        return nodes[node]->neighbors;
    }
    return {};
}