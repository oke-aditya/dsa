// Given a SORTED array A, find if the element is present or not
// If present, return the position

// arr[] = { 2, 3, 4, 10, 40 }; 
// x = 10; 

// Print element is found.

#include <bits/stdc++.h>

using namespace std;

int bsearch_itr(int arr[], int n, int tgt)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if tgt is present at mid
        if (arr[mid] == tgt)
        {
            return mid;
        }
        // If tgt greater, ignore left half
        if (tgt > arr[mid])
        {
            left = mid + 1;
        }
        // If tgt is smaller, ignore right half
        else if (tgt < arr[mid])
        {
            right = mid - 1;
        }
    }
    // if we reach here, then element was
    // not present
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 4, 10, 28};
    int tgt = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result2 = bsearch_itr(arr, n, tgt);

    if (result2)
    {
        cout << "Element is found" << endl;
    }
    else
    {
        cout << "Element is not found" << endl;
    }
    return (0);
}
