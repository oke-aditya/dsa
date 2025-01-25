// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. 
// Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
// We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the 
// packages on the conveyor belt being shipped within days days.

// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10


// Solution

// we need to estimate number of ships, so we need some guesswork
// we can start with 1 ship, say we have inf days, we can ship with just 1 capacity
// in case we just have 1 day, we will need sum(weights) capacity.

#include<bits/stdc++.h>

using namespace std;
bool is_possible(vector<int> &weights, int n, int mid, int days)
{
    int days_needed = 0;
    int run_sum = 0;
    for(int i=0; i<n; i++)
    {
        
        // too big for ship to carry even
        if(weights[i] > mid)
        {
            return false;
        }

        if(run_sum + weights[i] > mid)
        {
            run_sum = weights[i];
            days_needed += 1;
        }

        else
        {
            run_sum += weights[i];
        }
    }

    // in the end if we are left to ship something
    if(run_sum > 0)
    {
        days_needed += 1;
    }

    // if we have taken less or equal days to ship we are good
    return (days_needed <= days);

}


int shipWithinDays(vector<int>& weights, int days) 
{
    int left = 1;
    int sum = 0;
    int n = weights.size();

    for(auto w: weights)
    {
        sum += w;
    }

    int right = sum;

    int ans = -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        // if this works, then we can minimize our ships
        if(is_possible(weights, n, mid, days))
        {
            ans = mid;
            right = mid - 1;
        }

        // otherwise we atleast need mid ships.
        else
        {
            left = mid + 1;
        }
    }
    

    return ans;
}