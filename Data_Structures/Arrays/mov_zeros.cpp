// Move all zeroes to end of array

// Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
// For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, 
// it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. 
// The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).

// Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
// Output : arr[] = {1, 2, 4, 3, 5, 0, 0};

// Input : arr[]  = {1, 2, 0, 0, 0, 3, 6};
// Output : arr[] = {1, 2, 3, 6, 0, 0, 0};

#include<iostream>
void print_arr(int arr[], int n)
{
    for(int i=0; i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

void swap_zeros_simple(int arr[], int n)
{
    // Traverse the given array ‘arr’ from left to right. 
    // While traversing, maintain count of non-zero elements in array. Let the count be ‘count’. 
    // For every non-zero element arr[i], put the element at ‘arr[count]’ and increment ‘count’. 
    // After complete traversal, all non-zero elements have already been shifted to front end and 
    // ‘count’ is set as index of first 0. 
    // Now all we need to do is that run a loop which makes all elements zero from ‘count’ till end of the array.

    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] != 0)
        {
            arr[count] = arr[i];
            count += 1;
        }
    }

    while(count < n)
    {
        arr[count] = 0;
        count += 1;
    }
}

void swap_zeros_opt(int arr[], int n)
{
    // Initialize count = 0
    // for i = 0 to n-1
    //     if (arr[i] != 0) then
    //         swap(arr[count++], arr[i])

    int count = 0;
    for(int i=0; i<n;i++)
    {
        if(arr[i] != 0)
        {
            std::swap(arr[count], arr[i]);
            count += 1;
        }
    }
}

int main()
{
    int arr[] = {1,2,0,4,3,0,5,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // swap_zeros_simple(arr, n);
    swap_zeros_opt(arr, n);
    print_arr(arr, n);
    return(0);
}


