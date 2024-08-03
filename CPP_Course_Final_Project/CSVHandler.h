#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class csv_handler
{
public:
    explicit csv_handler(const std::string& file_name)
    {
        if (file_name.empty())
        {
            std::cout << "File name cannot be empty" << '\n';
            throw std::invalid_argument("File name cannot be empty");
        }
        
        if (file_name.find(".csv") == std::string::npos)
        {
            std::cout << "Only .csv files are supported at this point. Please provide a .csv file" << '\n';
            throw std::invalid_argument("Only .csv files are supported at this point. Please provide a .csv file");
        }
        
        raw_vector_data_ = std::vector<std::string>();
        parsed_vector_data_ = std::vector<std::vector<std::string>>();

        std::ifstream file(file_name);
        if (file.is_open())
        {
            std::string line;
            while (getline(file, line))
            {
                if (line.empty())
                {
                    continue;
                }
                
                raw_vector_data_.push_back(line);
            }
            file.close();
        }
        else
        {
            std::cout << "Unable to open file: " << file_name << '\n';
            throw std::runtime_error("Unable to open file: " + file_name);
        }

        if (raw_vector_data_.empty())
        {
            std::cout << "Given file is empty: " << file_name << '\n';
            throw std::runtime_error("Given file is empty: " + file_name);
        }
    }
    void parse_data();
    void print_data() const;
    void write_data_to_csv_file(const std::string& file_name) const;
    void write_data_to_json_file(const std::string& file_name) const;

private:
    std::vector<std::string> raw_vector_data_;
    std::vector<std::vector<std::string>> parsed_vector_data_;
};
