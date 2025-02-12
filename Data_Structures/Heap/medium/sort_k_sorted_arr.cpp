// Given an array of n elements, where each element
//  is at most k away from its target position,
// devise an algorithm that sorts in O(n log k) time. For example, 
// let us consider k is 2, an element at index 7 
// in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

// Example:
// Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
// k = 3 
// Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

// Solution: -
// Maintain a min heap, add first k elements.
// For next element, pop the top elements.
// Add the top element to a vector, it will be sorted.

#include<bits/stdc++.h>
using namespace std;

void nearly_sort(int arr[], int n, int k)
{
    // Simply we could sort the array and return it.
    sort(arr, arr + n);
}

vector<int> nearly_sort_heap(int arr[], int n, int k)
{
    // Declare a min heap

    priority_queue <int, vector<int>, greater<int>> minh;

    // Add first k elements of array to heap
    for(int i=0; i<=k; i++)
    {
        minh.push(arr[i]);
    }

    vector <int> res;
    for(int i=k+1; i<n; i++)
    {
        // Now pop top element for all remaining and push to result.
        res.push_back(minh.top());
        // Since we pushed the top we don't need it
        minh.pop();
        // Add new element to min heap
        minh.push(arr[i]);
    }

    // Pop the remaining min heap elments to result
    while(!minh.empty())
    {
        res.push_back(minh.top());
        minh.pop();
    }
    return res;
}

void print_vec(vector <int> v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    // nearly_sort(arr, n, k);

    auto res = nearly_sort_heap(arr, n, k);

    print_vec(res);

    return 0;
}


