#include "csvHandler.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std; 

void csvHandler::parseData(string fileName)
{
    ifstream file(fileName);
    string line;
    int row = 0;
    int col = 0;
    while (std::getline(file, line))
    {
        string name;
        for (char i : line)
        {
            if (i == ',')
            {
                data[row][col] = name;
                name = "";
                col++;
                continue;
            }
            name += i;
        }
        data[row][col] = name;
        // col = 0;
        row++;
    }

    cout << "Data:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
