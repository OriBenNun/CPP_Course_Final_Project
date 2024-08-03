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
            // throw std::runtime_error("Data is not valid for a graph. Aborting.");
        }
    }

    void print_graph() const;
private:
    std::vector<node> nodes_;
    bool try_populate_graph(const std::vector<std::vector<std::string>>& parsed_data);
    void add_node(const node& new_node);
};
