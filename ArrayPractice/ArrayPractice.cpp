
#include <iostream>
#include <ostream>

#include "ArrayContainer.h"

int main(int argc, char* argv[])
{
    auto array_container = ArrayContainer();
    array_container.init_array(50, true);
    array_container.print_array();
    array_container.order_array();
    std::cout << "Ordered Array:" << '\n';
    array_container.print_array();
    return 0;
}
