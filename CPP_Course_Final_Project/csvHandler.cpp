#include "csvHandler.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void csvHandler::parseData(string fileName)
{
    ifstream file(fileName);
    string line;
    int rows = 0;
    int cols = 0;
    while (std::getline(file, line))
    {
        string name;
        for (char i : line)
        {
            if (i == ',')
            {
                data_[rows][cols] = name;
                name = "";
                cols++;
                continue;
            }
            name += i;
        }
        data_[rows][cols] = name;
        cols = 0;
        rows++;
    }
    file.close();
}

void csvHandler::print_data()
{
    cout << "Data:" << '\n';
    for (int i = 0; i < data_array_size_; i++)
    {
        if (data_[i][0].empty())
        {
            break;
        }
        
        for (int j = 0; j < data_array_size_; j++)
        {
            auto item = data_[i][j];
            if (item.empty())
            {
                continue;
            }
            
            cout << item << " ";
        }
        cout << '\n';
    }
}
