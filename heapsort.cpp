/*
 * Heap is a complete binary tree represented in an array. Given a node i,
 * its parent, left child and right child are given by 
 *  PARENT(i) = floor(i/2)
 *  LEFT(i) = 2*i 
 *  RIGHT(i) = 2*i + 1
 *
 * NOTE: The above calculations assume that index 'i' starts from 1.
 *
 * Max-Heap: Max heap is a heap with the following property:
 *      For any node 'i' other than the root, A[PARENT(i)] >= A[i]
 *      ie. A node's value is utmost the value of the parent node
 *
 * Min-heap: Min heaps are similar to max heap where the parent has
 *           a value smaller than or equal to its children.
 *           A[PARENT(i)] <= A[i], for any node i other than root
 *
 * Height of Heap: Since the heap is a complete binary tree, the height
 *  of a heap with 'n' elements is O(log n).
 *
 * HeapSort Algorithm: This algorithm uses the max-heap to sort numbers.
 *  It has a complexity of O(n log n). 
 *
 *
 *  The functions below have the following complexity:
 *      max_heapify - O(log n) = O(height of tree)
 *      build_max_heap - O(n)
 *      heapsort- O(n log n)
 */

#include <iostream>
#include <vector>

#include "helper.h"

int left(int i)
{
    // LEFT(i) = 2*i
    // Since i starts from zero, I need to add one to it and subtract
    // it later.

    return 2*(i+1) - 1;
}

int right(int i)
{
    // RIGHT(i) = 2*i + 1

    return 2*(i+1) - 1 + 1;
}

int parent(int i)
{
    return ((i+1)/2);
}

int heap_size = 0;

void max_heapify (vector<int> &num, int i)
/*
 * Assumption: num[i] < num[LEFT(i)] || num[i] < num[RIGHT(i)]
 *             and sub-tree rooted at LEFT(i) and RIGHT(i) satisfy heap
 *             property
 */
{

    int largest;
    int l = left(i);
    int r = right(i);

    if (l < heap_size && num[i] < num[l])
        largest = l;
    else
        largest = i; // necessary to catch cases where 'i' has largest ele

    if (r < heap_size && num[r] > num[largest])
        largest = r;

    if (largest != i)
    {
        swap(num[i], num[largest]);
        max_heapify(num, largest);
    }

}

void build_max_heap(vector<int> &num)
/*
 * By heap structure, elements from num[N/2+1] to num[N] are the leaves of 
 * the heap. Therefore, we can assume them to be a single element heap and
 * run max-heapify on their parents to build the heap. All its parents are
 * present at locations [0, N/2] starting from N/2th position.
 */
{
    heap_size = num.size();

    for (int i=num.size()/2; i >=0; i--)
        max_heapify(num, i);
}

void heapsort(vector<int> &num)
{

    build_max_heap(num);
    heap_size = num.size();

    for (int i=num.size()-1; i >= 2; i--)
    {
        swap(num[0], num[i]);
        heap_size = i-1;
        max_heapify(num, 0);
    }
}

int main()
{
    vector<int> num(0);

    populate(num, 20);
    cout << "unordered nums: " << endl;
    print(num);

    heapsort(num);

    cout << "sorted nums: " << endl;
    print(num);

    return 0;
}
