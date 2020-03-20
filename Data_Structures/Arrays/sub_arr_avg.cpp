#include<iostream>
using namespace std;
// Find the subarray with least average
// Input:  arr[] = {3, 7, 90, 20, 10, 50, 40}, k = 3
// Output: Subarray between indexes 3 and 5
// The subarray {20, 10, 50} has the least average 
// among all subarrays of size 3.

// Input:  arr[] = {3, 7, 5, 20, -10, 0, 12}, k = 2
// Output: Subarray between [4, 5] has minimum average
void print_arr(int arr[], int n)
{
    for(int i=0; i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return;
}

void find_sub_arr_avg(int arr[], int k, int n)
{
    // Use the sliding window approach.
    // Slide the window of size k. Incrment 1 number and compute the new average.
    int window_size = k;
    int window_sum = 0;
    int min_window_sum = 99999;
    int window_del = 0;

    print_arr(arr,n);

    if(n<k)
    {
        std::cout<<"Not possible";
    }
    else
    {
        for(int i=0; i<k; i++)
        {
            window_sum += arr[i];
        }
        if(window_sum < min_window_sum)
        {
            min_window_sum = window_sum;
        }
        // cout<<min_window_sum<<endl;
        for(int i=k;i<n;i++)
        {
            // cout<<arr[i]<<endl;
            // break;
            window_sum += arr[i] - arr[window_del];
            window_del += 1;
            if(window_sum < min_window_sum)
            {
                min_window_sum = window_sum;
            }
        }
        cout<<endl<<min_window_sum;
    }
}


int main()
{
    int arr[] = {3, 7, 90, 20, 10, 50, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;  // Sub array size
    find_sub_arr_avg(arr, k, n);
    return(0);
}