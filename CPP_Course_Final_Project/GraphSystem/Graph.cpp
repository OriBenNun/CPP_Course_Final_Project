#include "Graph.h"

void graph::print_graph() const
{
    for (const auto& node : nodes_)
    {
        std::cout << node.name << " -> ";
        for (const auto& edge : node.get_edges())
        {
            std::cout << edge.first << " (" << edge.second << ") ";
        }
        std::cout << '\n';
    }
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
    if (parsed_data.empty())
    {
        return false;
    }

    for (auto& line : parsed_data)
    {
        if (line.size() < 2)
        {
            return false;
        }

        for (auto i = 0; i < static_cast<int>(line.size()); i += 3)
        {
            if (line[i].empty())
            {
                return false;
            }

            if (i + 1 > static_cast<int>(line.size()) || line[i + 1].empty() ||
                i + 2 > static_cast<int>(line.size()) || line[i + 2].empty())
                // line[i + 1].find_first_not_of("0123456789.") != std::string::npos ||
                // line[i + 2].find_first_not_of("0123456789.") != std::string::npos)
            {
                // Means that the following elements are missing
                return false;
            }

            if (line[i] == line[i + 2])
            {
                // Means that the for node and the to node are the same
                return false;
            }

            const std::string& from_node_name = line[i];
            
            double weight;

            // Now we need to check if the weight is a number
            try
            {
                weight = std::stod(line[i + 1]);
            }
            catch (...)
            {
                // Means that the weight is not a number
                return false;
            }
            const std::string& to_node_name = line[i + 2];

            // Now we can add the nodes to the graph
            
            // first, we create the nodes
            auto from_node = node(from_node_name);
            auto to_node = node(to_node_name);
            
            // then we add the edge between the nodes, in this case we're making a two ways graph
            from_node.add_edge(to_node, static_cast<float>(weight));
            to_node.add_edge(from_node, static_cast<float>(weight));

            // finally we add the nodes to the graph
            add_node(from_node);
            add_node(to_node);
        }
    }
    
    return true;
}

void graph::add_node(const node& new_node)
{
    nodes_.push_back(new_node);
}
