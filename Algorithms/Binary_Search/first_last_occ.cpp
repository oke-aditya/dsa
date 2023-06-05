// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Given a SORTED array with possibly duplicate elements,
// the task is to find indexes of first and last occurrences of an element x in the given array.

// Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}
//         x = 5
// Output : First Occurrence = 2
//          Last Occurrence = 5

// Input : arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125 }
//         x = 7
// Output : First Occurrence = 6
//          Last Occurrence = 6

// To find the first occurence, do not stop at returning mid.
// continue to search at left.

// To find the last occurence, do not stop at returning mid.
// Continute to search at right.

#include <bits/stdc++.h>
using namespace std;

int first_occurence(int arr[], int n, int tgt)
{
    int left = 0, right = n - 1;
    int res;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (tgt == arr[mid])
        {
            // return 1;
            // We are unsure so search left for first occurence.
            res = mid;
            right = mid - 1;
        }
        else if (tgt > arr[mid])
        {
            // Target on right, search right
            left = mid + 1;
        }
        else if (tgt < arr[mid])
        {
            // Target on left, search left
            right = mid - 1;
        }
    }
    return res;
}

int last_occurence(int arr[], int n, int tgt)
{
    int left = 0, right = n - 1;
    int res;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (tgt == arr[mid])
        {
            // continue search on right
            res = mid;
            left = mid + 1;
        }
        else if (tgt > arr[mid])
        {
            // search right
            left = mid + 1;
        }
        else if (tgt < arr[mid])
        {
            // search left
            right = mid - 1;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(int);
    int x = 5;

    cout << first_occurence(arr, n, x) << endl;
    cout << last_occurence(arr, n, x) << endl;

    return 0;
}
