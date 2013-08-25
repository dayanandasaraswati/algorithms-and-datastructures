/*
 * Complexity: theta (n log n) in average case. Note that the complexity is 
 *  theta and not big-O. Therefore, it is asymptotically closer to the actual
 *  performance with a very small constant factor. This makes quick sort 
 *  slightly better than merge sort for large inputs.
 *
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "helper.h"

using namespace std;

int partition(vector<int> &num, int p, int r)
{

    int pivot = num[r];
    int i = p-1;

    for (int j=p; j <= r-1; j++)
    {
       if (num[j] <= pivot)
       {
            i++;
            swap(num[i], num[j]);
       }
    }

    // i points to the end of "lesser-than" array. 
    // Copy the pivot to the end of this list
    swap(num[i+1], num[r]);
    return i+1;

}

void quicksort(vector<int> &num, int p, int r)
// NOTE: this routine will access elements from
// num[p] to num[r] both inclusive 
{
    // what is the correct termination condition?
    if ( p >= r || p < 0 || r >= num.size())
        return;

    int q = partition(num, p, r);
    quicksort(num, p, q-1);
    quicksort(num, q+1, r);
}

int main()
{
    
    vector<int> num(0);

    populate(num, 20);

    cout << "unsorted nums:" << endl;
    print (num);

    quicksort(num, 0, num.size()-1);
    
    cout << "sorted nums:" << endl;
    print(num);

}
