// https://leetcode.com/problems/number-of-good-pairs/
// Given an array of integers nums.

// A pair (i,j) is called good if nums[i] == nums[j] and i < j.

// Return the number of good pairs.

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

// Solution

// We can just count each value. Then, n elements with the same value can form n * (n - 1) / 2 pairs.


#include<bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) 
{
    // maintain a map that captures no of occurences?
    unordered_map<int, int> mp;
    for(auto num: nums)
    {
        mp[num] += 1;
    }

    int count = 0;
    int freq;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    {
        freq = itr->second;
        count = count + (freq * (freq - 1) / 2);
    }

    return count;
}

int main(int argc, char const *argv[])
{
    vector <int> v1 = {1, 2, 3, 1, 1, 3};
    vector <int> v2 = {1, 1, 1, 1};

    int res1 = numIdenticalPairs(v1);
    int res2 = numIdenticalPairs(v2);

    cout<<res1<<endl;
    cout<<res2<<endl;

    
    return 0;
}

