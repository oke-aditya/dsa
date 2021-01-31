// Find the Missing Number

// You are given a list of n-1 integers and these integers are in the range of 1 to n.
// There are no duplicates in the list.
// One of the integers is missing in the list.
// Write an efficient code to find the missing

// Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
// Output: 5

// Input: arr[] = {1, 2, 3, 5}
// Output: 4

#include <iostream>

void miss_no_s(int arr[], int n)
{
    int ac_sum = (n + 1) * (n + 2) / 2;
    int calc_sum = 0;
    for (int i = 0; i < n; i++)
    {
        calc_sum += arr[i];
    }
    std::cout << ac_sum - calc_sum;
    std::cout << std::endl;
}

void miss_no_xor(int arr[], int n)
{
    int x_s_cal = arr[0];
    int x_s_act = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        x_s_act ^= i;
    }
    for (int i = 1; i < n; i++)
    {
        x_s_cal ^= arr[i];
    }
    std::cout << (x_s_act ^ x_s_cal);
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    miss_no_s(arr, n);
    miss_no_xor(arr, n);
    return (0);
}
