#pragma once
#include <string>
using namespace std;

class csvHandler
{
public:
    void parseData(string fileName = "data.csv");

private:
    string data[100][100];
};
