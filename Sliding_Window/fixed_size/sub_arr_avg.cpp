#include<bits/stdc++.h>
using namespace std;

// Find the subarray with least average
// Input:  arr[] = {3, 7, 90, 20, 10, 50, 40}, k = 3
// Output: Subarray between indexes 3 and 5
// The subarray {20, 10, 50} has the least average 
// among all subarrays of size 3.

// Input:  arr[] = {3, 7, 5, 20, -10, 0, 12}, k = 2
// Output: Subarray between [4, 5] has minimum average

void print_v(vector <int> v)
{
    for(auto x : v)
    {
        cout<<x<<" ";
    }
}

int find_sub_arr_avg(vector <int> v, int k)
{
    int n = v.size();
    // Do calculation for first sub array of size k.
    int wind_avg = -1;
    int wind_sum = 0;
    for(int j=0; j<k; j++)
    {
        wind_sum += v[j];
    }
    wind_avg = wind_sum / k;
    // Now add next element and remove calculations of previous.
    // i is pointer to start of window, j is to end of window.
    int i = 0;
    
    int min_avg = wind_avg;
    
    for(int j=k; j<n; j++)
    {
        wind_sum = wind_sum + v[j] - v[i];
        wind_avg = wind_sum / k;
        min_avg = min(min_avg, wind_avg);
        
        // Move ith pointer.
        i += 1;
    }
    return min_avg;

    // To search for minimum avg. Use the computed minimum average and find it
    
}

int main()
{
    vector <int> v {3, 7, 90, 20, 10, 50, 40};
    int k = 3;  // Sub array size
    auto min_avg = find_sub_arr_avg(v, k);
    cout<<min_avg<<endl;
    return(0);
}
