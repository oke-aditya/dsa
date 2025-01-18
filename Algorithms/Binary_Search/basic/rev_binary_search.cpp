// Given a reverse sorted array, apply binary search
// int arr[] = {40, 28, 10, 5, 1}
// x = 10; 

// Print element is found.

#include<bits/stdc++.h>
using namespace std;

int bsearch_rev(int arr[], int n, int tgt)
{
    int left = 0;
    int right = n-1;
    while(left <= right)
    {
        // int mid = (left + right) / 2;
        int mid = left + (right - left) / 2;

        if(arr[mid] == tgt)
        {
            return mid;
        }
        else if(tgt < arr[mid])
        {
            left = mid + 1;
        }
        else if(tgt > arr[mid])
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {40, 28, 10, 5, 1};
    int tgt=10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = bsearch_rev(arr, n, tgt);
    if(res)
    {
        cout<<"Element is found"<<endl;
    }
    else
    {
        cout<<"Element is not found"<<endl;
    }
    

    return 0;
}

