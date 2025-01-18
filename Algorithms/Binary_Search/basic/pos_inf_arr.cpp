// Find position of an element
// in a sorted array of infinite numbers

// Suppose you have a sorted array of infinite numbers,
// how would you search an element in the array?

// If the array is infinite, that means we don’t have proper bounds to apply binary search.
// So in order to find position of key, first we find bounds and then apply binary search algorithm.

// Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
// ->if it is greater than high index element then copy high index in low index and double the high index.
// ->if it is smaller, then apply binary search on high and low indices found.

#include <bits/stdc++.h>
using namespace std;

int bin_search(int arr[], int left, int right, int tgt)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(tgt == arr[mid])
        {
            return mid;
        }
        else if(tgt > arr[mid])
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

int find_pos(int arr[], int key)
{
    int left=0;
    // We don't konw the right, so we need to find it;
    int right=1;
    int val = arr[0];
    
    // Find the appropriate right
    while(val< key)
    {
        left = right;
        right = 2*right;
        val = arr[left];
    }
    // At end of this we will have  left and right

    // now do binary search between left and right
    int res = bin_search(arr, left, right, key);
    return res;

}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int ans = find_pos(arr, 10);

    cout << ans << endl;

    return 0;
}
