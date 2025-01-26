// Given an infinite sorted array consisting 0s and 1s.
// The problem is to find the index of first ‘1’ in that array.
// As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

// Input : arr[] = {0, 0, 1, 1, 1, 1} 
// Output : 2

// Input : arr[] = {1, 1, 1, 1,, 1, 1}
// Output : 0

// Solution: -
// Very similar to finding position of element in infinite array.
// First find the left and right bounds.
// Then do modified binary search to return the first element.


#include<bits/stdc++.h>
using namespace std;

int bin_firstoccur(int arr[], int left, int right, int tgt)
{
    int res;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(tgt == arr[mid])
        {
            res = mid;
            right = mid - 1;
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

int index_first(int arr[])
{
    int left=0, right = 1;
    while(arr[left] == 0)
    {
        left = right;
        right = right * 2;
    }

    // Now we have left and right, apply binary search to get first occurence

    int res = bin_firstoccur(arr, left, right, 1);

    return res;

}


int main(int argc, char const *argv[])
{
    int arr[] = {0, 0, 1, 1, 1, 1};
    
    cout<<index_first(arr)<<endl;

    return 0;
}

