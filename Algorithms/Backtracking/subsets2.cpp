// https://leetcode.com/problems/subsets-ii/

// Given an integer array nums that may contain duplicates
//  return all possible subsets (the power set).

// The solution set must not contain duplicate subsets.
// return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

#include<bits/stdc++.h>
using namespace std;

void print_vv(vector <vector<int>> vv)
{
    for(auto v : vv)
    {
        cout<<"[";
        for(auto ele: v)
        {
            cout<<ele<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}

void backtrack(vector<vector<int>> &res, vector<int> temp,
               vector<int> nums, int start)
{
    res.push_back(temp);
    for(int i=start; i<nums.size(); i++)
    {
        // Check for duplicates.
        if(i > start && nums[i] == nums[i-1])
        {
            // skip this element.
            continue;
        }

        // Either we include it
        temp.push_back(nums[i]);

        backtrack(res, temp, nums, i+1);

        // If we don't include it.
        temp.pop_back();
    }

}

vector<vector<int>> find_subsets(vector<int> nums)
{
    vector<vector<int>> res;
    vector<int> temp;

    sort(nums.begin(), nums.end());

    backtrack(res, temp, nums, 0);
    return res;

}


int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 2, 2};
    vector<int> v2 = {0};

    auto res1 = find_subsets(v1);
    auto res2 = find_subsets(v2);

    print_vv(res1);
    print_vv(res2);

    return 0;
}

