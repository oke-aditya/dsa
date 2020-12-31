
// Find all triplets with zero sum

// Given an array of distinct elements. The task is to find triplets in array whose sum is zero.
// Input : arr[] = {0, -1, 2, -3, 1}
// Output : 0 -1 1
//          2 -3 1

// Input : arr[] = {1, -2, 1, 0, 5}
// Output : 1 -2  1

#include<iostream>
using namespace std;

void find_triplets_bf(int arr[], int n)
{
    // Brute force search to find all the triplets
    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    cout<<endl<<arr[i]<<" "<<arr[j]<<" "<<arr[k];
                }
            }
        }
    }
}

void find_triplets_opt(int arr[], int n)
{
    
}

int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/ sizeof(arr[0]);

    find_triplets_bf(arr, n);
    return(0);
}