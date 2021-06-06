// The selection sort algorithm sorts an array by repeatedly finding the minimum element
// (considering ascending order) from unsorted part and putting it at the beginning.
// The algorithm maintains two subarrays in a given array.
// 1) The subarray which is already sorted.
// 2) Remaining subarray which is unsorted.

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void selection_sort(vector<int> &arr)
{
    int i, j, min_idx;

    for (i = 0; i < arr.size() - 1; i++)
    {
        // find the smallest element index.
        min_idx = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }

        }
        // Swap the smallest element and the given index.
        swap(arr[min_idx], arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 5, -1, 7, 0, 2, 33, 1};
    selection_sort(arr);
    print_v(arr);

    return 0;
}
