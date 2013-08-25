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

void print(vector< vector<int> > &array2d)
{
    for (int i=0; i < array2d.size(); i++)
    {
        for(int j=0; j < array2d.size(); j++)
            cout << array2d[i][j] << "  ";

        cout << endl;
    }

}

void graphgen(vector< vector<int> > &adjmat)
{
    // FIXME: rand() function isn't random enough. So I end up getting
    // 1's at most places in the matrix.
    
    srand(time(NULL));

    for (int i=0; i < adjmat.size(); i++)
        for(int j = i-1; j >= 0; j--)
            adjmat[i][j] = adjmat[j][i] = rand() % 2;

    for (int i=0; i < adjmat.size(); i++)
        adjmat[i][i] = 0;
}


