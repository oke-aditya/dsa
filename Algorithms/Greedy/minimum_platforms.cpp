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

#include <bits/stdc++.h>
using namespace std;

int minimal_platform(vector<int> arr, vector<int> dep)
{
    
}

int main(int argc, char const *argv[])
{
    int n = 6;
    // Starting time is not sorted.
    vector<int> arr = {900, 940, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    auto res = minimal_platform(arr, dep);
    cout << res << endl;

    return 0;
}
