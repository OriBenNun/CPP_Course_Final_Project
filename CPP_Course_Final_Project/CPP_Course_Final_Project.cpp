
#include <string>

#include "CSVHandler.h"

int main(int argc, char* argv[])
{
    std::string file_name = "data.csv";
    // Here we create a new CSVHandler to parse the data and store it in a vector
    csv_handler csv_handler(file_name);
    csv_handler.parse_data();
    csv_handler.print_data();
    return 0;
}
