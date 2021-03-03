// https://leetcode.com/problems/subsets/

// Given an integer array nums of unique elements,
// return all possible subsets (the power set).

// The solution set must not contain duplicate subsets.
// Return the solution in any order.

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

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

    for(int i=start;i<nums.size(); i++)
    {
        // We can either choose the element or avoid it
        temp.push_back(nums[i]);
        backtrack(res, temp, nums, i+1);

        // If we don't choose the current number.
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
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {0};

    auto res1 = find_subsets(v1);
    auto res2 = find_subsets(v2);

    print_vv(res1);
    print_vv(res2);

    return 0;
}

