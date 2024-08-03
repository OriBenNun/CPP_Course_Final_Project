
#include <string>

#include "CSVHandler.h"
#include "GraphSystem/Graph.h"

void csv_handler_test(const std::string& file_name)
{
    csv_handler csv_handler(file_name);
    csv_handler.parse_data();
    csv_handler.print_data();
    std::string csv_write_file_name = "csv_parsed_data.csv";
    csv_handler.write_data_to_csv_file(csv_write_file_name);

    std::string json_write_file_name = "json_parsed_data.json";
    csv_handler.write_data_to_json_file(json_write_file_name);
}

int main(int argc, char* argv[])
{

    // here we get the file name from the user
    std::string file_name;
    std::cout << "Enter the file name (should be a .csv file inside the same folder as this .exe): ";
    std::cin >> file_name;

    csv_handler csv_handler(file_name);
    csv_handler.parse_data();
    auto parsed_data = csv_handler.get_parsed_data();

    // Now we create a graph class to store the data as a graph data structure
    const graph graph(parsed_data);
    graph.print_graph();
    
    return 0;
}
