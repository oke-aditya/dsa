// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Notice that the solution set must not contain duplicate quadruplets.

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Input: nums = [], target = 0
// Output: []

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector <int> v)
{
    vector <vector<int>> res;

    if(v.empty())
    {
        return res;
    }

    int n = v.size();
    sort(v.begin(), v.end());

    
    

}

int main(int argc, char const *argv[])
{
    vector <int> v = {1, 0, -1, 0, -2, 2};
    auto res = four_sum(v);

    return 0;
}

