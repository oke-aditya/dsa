// Minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day.
// Arrival and departure time can never be the same for a train but we can have arrival
// time of one train equal to departure time of the other. At any given instance of time,
// same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms,

// Input: N = 6
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation:
// Minimum 3 platforms are required to
// safely arrive and depart all trains.

// Input: N = 3
// arr[] = {0900, 1100, 1235}
// dep[] = {1000, 1200, 1240}
// Output: 1
// Explanation: Only 1 platform is required to
// safely manage the arrival and departure
// of all trains.

// Solution: -
// Since we do not to worry about train ids.
// We can sort each of the arrays individually. It will not matter.
// After sorting we still have the details which trains are going to come and go.
// Now, we greedily allocate trains that depart early.
// 
// 

#include <bits/stdc++.h>
using namespace std;

int minimal_platform(vector<int> arr, vector<int> dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plt_needed = 1, max_plt = 1;
    int i = 1, j = 0;

    while(i < arr.size() && j < dep.size())
    {
        if(arr[i] <= dep[j])
        {
            plt_needed += 1;
            i += 1;
        }

        else if(arr[i] > dep[j])
        {
            plt_needed -= 1;
            j += 1;
        }

        if(plt_needed > max_plt)
        {
            max_plt = plt_needed;
        }
    }
    return max_plt;
}

int main(int argc, char const *argv[])
{
    int n = 6;
    // Starting time is not sorted.
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    auto res = minimal_platform(arr, dep);
    cout << res << endl;

    return 0;
}
