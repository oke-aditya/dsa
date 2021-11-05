// Given a SORTED array arr[] and a number x,
// write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn)

// Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
// Output: 4 // x (or 2) occurs 4 times in arr[]

// Solution: -
// Since array is sorted, simple we need the left end and the right end.
// Difference of them will give us the count

#include <bits/stdc++.h>
using namespace std;

int bsearch_left(int arr[], int n, int tgt)
{
    int left = 0, right = n - 1, res;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            // search left
            res = mid;
            right = mid - 1;
        }
        else if (tgt > arr[mid])
        {
            // search right
            left = mid + 1;
        }
        else if (tgt < arr[mid])
        {
            right = mid - 1;
        }
    }
    return res;
}

int bsearch_right(int arr[], int n, int tgt)
{
    int left = 0, right = n - 1, res;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            res = mid;
            left = mid + 1;
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
    return res;
}

int count_occurence(int arr[], int n, int tgt)
{
    int left_pos = bsearch_left(arr, n, tgt);
    int right_pos = bsearch_right(arr, n, tgt);
    return (right_pos - left_pos + 1);
}

int main(int argc, char const *argv[])
{

    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << count_occurence(arr, n, x) << endl;
    return 0;
}
