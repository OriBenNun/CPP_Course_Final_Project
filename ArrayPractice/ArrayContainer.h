#pragma once

class ArrayContainer
{
private:
    int* array_;
    int array_size_;
public:
    void init_array(int size, bool insertRandom);
    void order_array();
    void print_array();
};
