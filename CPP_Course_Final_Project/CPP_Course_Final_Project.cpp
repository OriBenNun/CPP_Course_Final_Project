
#include "csvHandler.h"

int main(int argc, char* argv[])
{
    csvHandler csv_handler = csvHandler();
    csv_handler.parseData();
    csv_handler.print_data();
    return 0;
}
