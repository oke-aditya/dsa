#include<bits/stdc++.h>
using namespace std;

// Given an unsorted array, find a pair with given sum
// E.g. arr = [8, 7, 2, 3, 1]
// sum = 10
// Output Pair found at (8, 2) and (7, 3)

void find_pair_brute(int arr[], int n, int sum)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((arr[i] + arr[j]) == sum)
            {
                cout<<arr[i]<<" "<<arr[j];
                cout<<endl;
            }
        }
    }
}

void find_pair_twopt(int arr[], int n, int sum)
{
    sort(arr, arr+n);
    int left_ptr = 0;
    int right_ptr = n-1;

    while (left_ptr < right_ptr)
    {
        if(arr[left_ptr] + arr[right_ptr] < sum)
        {
            left_ptr += 1;
        }
        else if(arr[left_ptr] + arr[right_ptr] > sum)
        {
            right_ptr -= 1;
        }
        else
        {
            cout<<arr[left_ptr]<<" "<<arr[right_ptr];
            cout<<endl;
            left_ptr += 1;
            right_ptr -= 1;
        }   
    }
}

void find_pair_opt(int arr[], int n, int sum)
{
    // Create an unordered map
    unordered_map<int, int> map;

    // For each element
    for(int i=0; i<n; i++)
    {
        // Check if pair (arr[i], sum-arr[i]) exists
        if(map.find(sum - arr[i]) != map.end())
        {
            // Exists so add it
            cout<<sum - arr[i]<<" "<<arr[i]<<endl;
        }
        else
        {
            map[arr[i]] = i;
        }
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {8, 7, 2, 5, 3, 1};
    int sum = 10;

    int n = sizeof(arr) / sizeof(arr[0]);
    find_pair_brute(arr, n, sum);
    find_pair_twopt(arr, n, sum);
    find_pair_opt(arr, n, sum);

    return 0;
}
