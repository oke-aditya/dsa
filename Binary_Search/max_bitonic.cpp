// Given a bitonic array find the maximum value of the array.
// An array is said to be bitonic if it has an increasing sequence of integers followed
// immediately by a decreasing sequence of integers.
// Example:

// Input:
// 1 4 8 3 2

// Output:
// 8

// Solution: -
// Maximum value in bitonic array is the peak element. So just search for peak element.

#include <bits/stdc++.h>
using namespace std;

int max_bitonic(int arr[], int n)
{
    int left = 0, right = n - 1, res;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                // This is peak.
                return arr[mid];
            }
            else if (arr[mid - 1] > arr[mid])
            {
                // left element is greater so search there
                right = mid - 1;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                // right element is greater so search there
                left = mid + 1;
            }
        }

        // Edge cases
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

int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 8, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res = max_bitonic(arr, n);

    cout << res << endl;

    return 0;
}
