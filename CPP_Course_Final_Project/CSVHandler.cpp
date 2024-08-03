#include "CSVHandler.h"

#include <iostream>

void csv_handler::parse_data()
{
    parsed_vector_data_.clear();

    for (const auto& line : raw_vector_data_)
    {
        auto parsed_line = std::vector<std::string>();
        auto current_word = std::string();
        for (const char item : line)
        {
            if (item == ',')
            {
                parsed_line.push_back(current_word);
                current_word = "";
            }
            else
            {
                current_word += item;
            }
        }
        if (!current_word.empty())
        {
            parsed_line.push_back(current_word);
        }
        parsed_vector_data_.push_back(parsed_line);
    }
}

void csv_handler::print_data() const
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

void csv_handler::write_data_to_csv_file(const std::string& file_name) const
{
    std::ofstream file(file_name);
    if (file.is_open())
    {
        for (const auto& line : parsed_vector_data_)
        {
            for (const auto& item : line)
            {
                file << item << ",";
            }
            file << "\n";
        }
        file.close();
        std::cout << "Data written to file: " << file_name << "" << '\n';
    }
    else
    {
        std::cout << "Unable to open file: " << file_name << "" << '\n';
    }
}

void csv_handler::write_data_to_json_file(const std::string& file_name) const
{
    std::ofstream file(file_name);
    if (file.is_open())
    {
        file << "[" << "\n";
        auto line_number = 1;
        for (const auto& line : parsed_vector_data_)
        {
            // here we write the data in json format:
            // {"line Number": 1, "values": ["item1", "item2", "item3"]}
            
            auto values = std::string();
            for (const auto& item : line)
            {
                values += "\"" + item + "\",";
            }
            values = values.substr(0, values.size() - 1);
            
            file << "{" << "\"line Number\": " << line_number++ <<
                ", \"values\": [" << values << "]},";
            file << "\n";
        }
        // we remove the last "," before closing the json array
        file.seekp(-1, std::ios_base::cur);
        file.seekp(-1, std::ios_base::cur);
        file.seekp(-1, std::ios_base::cur);
        
        file << "\n" << "]";
        file.close();
        std::cout << "Data written to file: " << file_name << "" << '\n';
    }
    else
    {
        std::cout << "Unable to open file: " << file_name << "" << '\n';
    }
}
