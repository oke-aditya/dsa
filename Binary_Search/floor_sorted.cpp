#include <bits/stdc++.h>
using namespace std;

// Given a sorted array and a value x, the floor of x is
// the largest element in array smaller than or equal to x.
// Write efficient functions to find floor of x.

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
// Output : 2
// 2 is the largest element in
// arr[] smaller than 5.

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
// Output : 19
// 19 is the largest element in
// arr[] smaller than 20.

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
// Output : -1
// Since floor doesn't exist,
// output is -1.

int find_floor(int arr[], int tgt, int n)
{
    int left = 0;
    int right = n - 1;
    int res;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            return arr[mid];
        }
        else if (tgt > arr[mid])
        {
            res = arr[mid];
            left = mid + 1;
        }
        else if (tgt < arr[mid])
        {
            right = mid - 1;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int tgt = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = find_floor(arr, tgt, n);

    cout << res << endl;

    return 0;
}
