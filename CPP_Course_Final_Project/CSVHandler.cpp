#include "CSVHandler.h"

#include <iostream>

void csv_handler::parse_data()
{
    // here we parse the raw vector data into the parsed vector
    parsed_vector_data_.clear();
    for (const auto& line : raw_vector_data_)
    {
        int counter = 0;
        auto parsed_line = std::vector<char>();
        for (const char item : line)
        {
            if (item == ',')
            {
                counter++;
            }
            else
            {
                parsed_line.push_back(line[counter - 1]);
            }
        }
        parsed_vector_data_.push_back(parsed_line);
    }
}

void csv_handler::print_data()
{
    for (const auto& line : parsed_vector_data_)
    {
        for (const auto& item : line)
        {
            std::cout << item << " ";
        }
        std::cout << '\n';
    }
}
