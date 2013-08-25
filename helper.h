#pragma once

#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

void populate(vector<int> &num, int length)
{
    
    srand(time(NULL));

    for (int i=0; i < length; i++)
    {
        num.push_back(rand() % 100);
    }
}

void print(vector<int> &num)
{
    for (int i=0; i < num.size(); i++)
        cout << num[i] << ", ";

    cout << endl;

}
