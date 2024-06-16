#pragma once
#include <string>
using namespace std;

class csvHandler
{
public:
    void print_data();
    void parseData(string fileName = "data.csv");

private:
    string data_[100][100];
    int data_array_size_ = 100;
};
