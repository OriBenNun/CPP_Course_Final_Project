
#include <string>

#include "CSVHandler.h"

int main(int argc, char* argv[])
{

    // here we get the file name from the user
    std::string file_name;
    std::cout << "Enter the file name (should be a .csv file inside the same folder as this .exe): ";
    std::cin >> file_name;
    
    // Here we create a new CSVHandler to parse the data and store it in a vector
    csv_handler csv_handler(file_name);
    csv_handler.parse_data();
    csv_handler.print_data();
    std::string csv_write_file_name = "csv_parsed_data.csv";
    csv_handler.write_data_to_csv_file(csv_write_file_name);

    std::string json_write_file_name = "json_parsed_data.json";
    csv_handler.write_data_to_json_file(json_write_file_name);
    
    return 0;
}
