// Given an array and a number k where k is smaller than size of array, we need to find the
// k’th smallest element in the given array. It is given that all array elements are distinct.

// Example:
// Input: arr[] = {7, 10, 4, 3, 20, 15}
// k = 3
// Output: 7

// k = 4
// Output: 10

// k = 1
// Output: 3

// Solution: -

// Use max heap since, kth smallest is required.

// Note that kth smallest element is also (n-k)th largest element in the array.

// For kth largest element question simply find (n-k)th smallest element from this logic.

#include <bits/stdc++.h>
using namespace std;

int k_small_sort(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

int k_small_heap(int arr[], int n, int k)
{
    // Create a max heap
    priority_queue<int> maxh;
    // Push elements one by one
    // Keep only k elments in heap.
    for (int i = 0; i < n; i++)
    {
        maxh.push(arr[i]);

        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }

    // top denotes the kth top most elment
    return maxh.top();

    // To print k smallest elements
    // simple do the following
    // vector <int> v;
    // while(!maxh.empty())
    // {
    //     v.push_back(maxh.top());
    //     maxh.pop();
    // }
    // return v
}

int main(int argc, char const *argv[])
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << k_small_sort(arr, n, k) << endl;
    cout << k_small_heap(arr, n, k) << endl;

    return 0;
}
