// Check if subarray with 0 sum is exists or not

#include <bits/stdc++.h>
using namespace std;

bool zeroSumSubarray(int arr[], int n)
{
    unordered_set<int> s1;
    // Handle case if arr starts with 0;
    s1.insert(0);

    int running_sum = 0;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        running_sum += arr[i];
        if (s1.find(running_sum) != s1.end())
        {
            // We found the sum
            return true;
        }
        else
        {
            s1.insert(running_sum);
        }
    }
    // We reach end without doing anyting
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 2, -3, -1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Subarray with 0 sum exists
    // Subarrays must be with contigous locations, occupy consecutive positions
    if (zeroSumSubarray(arr, n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
