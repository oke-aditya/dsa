// https://leetcode.com/problems/subsets/description/
// Given an integer array nums of unique elements, return all possible
// subsets
// (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// The recursive tree is very similar.
// But note that here every node is a solution.
// We can also do using bitmasking but this is far easier.


#include<bits/stdc++.h>
using namespace std;

void print_vv(vector<vector<int>> vv)
{
    for(auto v: vv)
    {
        cout<<"[";
        for(auto x: v)
        {
            cout<<x<<",";
        }
        cout<<"],";
    }
}

void generate_subsets(vector<int> &nums, int start, vector<vector<int>> &res, vector<int> &sol)
{
    // Since solution is not in leaf node, but every node of recursive tree is the solution
    res.push_back(sol);

    // for every combination we want to generate subsets
    for(int i=start; i<nums.size(); i++)
    {
        sol.push_back(nums[i]);
        // since we can process just once, we do i+1

        // To drop duplicates we can sort and check below, note order is important.
        // if((i > start) && (nums[i] == nums[i-1]))
        // {
        //     // skip this element.
        //     continue;
        // }

        generate_subsets(nums, i+1, res, sol);
        sol.pop_back();
    }
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sol;
    int start = 0;
    generate_subsets(nums, start, res, sol);
    return res;    
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    auto res = subsets(nums);
    print_vv(res);
    return 0;
}


