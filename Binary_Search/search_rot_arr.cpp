// Given an array which is sorted, but after
// sorting some elements are moved to either of the adjacent positions,
// i.e., arr[i] may be present at arr[i+1] or arr[i-1].

// Write an efficient function to search an element in this array.
// Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2
// Output is index of 40 in given array

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
// Output: -1
// -1 is returned to indicate element is not present

// Solution
// The idea is to compare the key with middle 3 elements,
// if present then return the index.
// If not present, then compare the key with middle element to decide whether
// to go in left half or right half.
// Comparing with middle element is enough as all the elements after mid+2
// must be greater than element mid and all elements before mid-2 must be smaller than mid element
//

#include <bits/stdc++.h>
using namespace std;

int search_rot_arr(int arr[], int n, int tgt)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            return mid;
        }
        else if (mid > left && arr[mid - 1] == tgt)
        {
            return mid - 1;
        }
        else if (mid < right && arr[mid + 1] == tgt)
        {
            return mid + 1;
        }

        if (tgt < arr[mid])
        {
            right = mid - 2;
        }
        else if (tgt > arr[mid])
        {
            left = mid + 2;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int target = 40;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = search_rot_arr(arr, n, target);
    cout << res << endl;

    return 0;
}
