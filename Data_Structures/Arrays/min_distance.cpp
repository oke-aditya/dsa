
// Find the minimum distance between two numbers

// Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. The array might also contain duplicates. You may assume that both x and y are different and present in arr[].

// Examples:
// Input: arr[] = {1, 2}, x = 1, y = 2
// Output: Minimum distance between 1 and 2 is 1.

// Input: arr[] = {3, 4, 5}, x = 3, y = 5
// Output: Minimum distance between 3 and 5 is 2.

// Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
// Output: Minimum distance between 3 and 6 is 4.

// Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
// Output: Minimum distance between 3 and 2 is 1.

#include <iostream>
#include <climits>
using namespace std;

int minDist(int arr[], int n, int x, int y)
{
    int min_dist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x == arr[i] && y == arr[j] || y == arr[i] && x == arr[j])
            {
                if (min_dist > abs(i - j))
                {
                    min_dist = abs(i - j);
                }
            }
        }
    }
    return min_dist;
}

int main()
{
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int y = 6;

    cout << "Minimum distance between " << x << " and " << y << " is " << minDist(arr, n, x, y) << endl;
}