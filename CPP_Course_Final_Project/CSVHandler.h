#pragma once
#include <fstream>
#include <string>
#include <vector>

class csv_handler
{
public:
    explicit csv_handler(const std::string& file_name)
    {
        raw_vector_data_ = std::vector<std::string>();
        parsed_vector_data_ = std::vector<std::vector<char>>();
        // here we store the data from the file
        std::ifstream file(file_name);
        if (file.is_open())
        {
            std::string line;
            while (getline(file, line))
            {
                raw_vector_data_.push_back(line);
            }
            file.close();
        }
    }
    void parse_data();
    void print_data();
private:
    std::vector<std::string> raw_vector_data_;
    std::vector<std::vector<char>> parsed_vector_data_;
};
