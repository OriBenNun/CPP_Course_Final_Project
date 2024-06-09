#include "ArrayContainer.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

void ArrayContainer::init_array(int size, bool insertRandom)
{
    array_size_ = size;
    array_ = new int[size];
    if (insertRandom)
    {
        for (int i = 0; i < size; i++)
        {
            array_[i] = rand() % 100;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            array_[i] = i + 1;
        }
    }
}

void ArrayContainer::order_array()
{
    for (int i = 0; i < array_size_; i++)
    {
        for (int j = 0; j < array_size_; j++)
        {
            if (array_[i] < array_[j])
            {
                const int temp = array_[i];
                array_[i] = array_[j];
                array_[j] = temp;
            }
        }
    }
}

void ArrayContainer::print_array()
{
    for (int i = 0; i < array_size_; i++)
    {
        std::cout << array_[i] << " ";
    }
    std::cout << '\n';
}
