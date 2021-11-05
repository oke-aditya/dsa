// Find element in bitonic array.
// Input :  arr[] = {-3, 9, 18, 20, 17, 5, 1};
//          key = 20
// Output : Found at index 3

// Input :  arr[] = {5, 6, 7, 8, 9, 10, 3, 2, 1};
//          key = 30
// Output : Not Found

// Solution: -
// First find the peak element of the array.
// Left half of array to peak element is ascending.
// Right half of array to peak element is descending.
// Apply binary search on each of these halves.

#include <bits/stdc++.h>
using namespace std;

int peak_idx(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                // Greater on both sides, return the position.
                return mid;
            }
            else if (arr[mid - 1] > arr[mid])
            {
                // Search on left.
                right = mid - 1;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                // Search on right
                left = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (arr[0] > arr[1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
            {
                return n - 1;
            }
            else
            {
                return n - 2;
            }
        }
    }
    return -1;
}

int binary_asc(int arr[], int left, int right, int tgt)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            return mid;
        }
        else if (tgt > arr[mid])
        {
            left = mid + 1;
        }
        else if (tgt < arr[mid])
        {
            right = mid - 1;
        }
    }
    return -1;
}

int binary_desc(int arr[], int left, int right, int tgt)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            return mid;
        }
        else if (tgt > arr[mid])
        {
            right = mid - 1;
        }
        else if (tgt < arr[mid])
        {
            left = mid + 1;
        }
    }
    return -1;
}

int bit_search(int arr[], int n, int key)
{
    int peak_index = peak_idx(arr, n);
    int bsearch_left = binary_asc(arr, 0, peak_index, key);
    int bsearch_right = binary_desc(arr, peak_index + 1, n, key);

    if (bsearch_left != -1)
    {
        return bsearch_left;
    }
    else if (bsearch_right != -1)
    {
        return bsearch_right;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {-3, 9, 18, 20, 17, 5, 1};
    int key = 20;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << bit_search(arr, n, key) << endl;

    return 0;
}
