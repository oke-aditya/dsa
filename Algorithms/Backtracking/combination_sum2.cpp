// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

// Solution
// Same appraoch as combination sum 1
// We just have to increase i if we have picked the element.
// Else we can avoid it.

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
              vector<int> nums, int target, int start)
{
    if(target < 0)
    {
        return;
    }
    // We have a solution!
    else if(target == 0)
    {
        res.push_back(temp);
    }
    else
    {
        for(int i=start; i<nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i-1])
            {
                // Skip this duplicate element
                continue;
            }

            // We can choose this element
            temp.push_back(nums[i]);

            // Now we have to reduce the target and backtrack.
            // We can take element just once so move ahead.
            backtrack(res, temp, nums, target-nums[i], i+1);
            temp.pop_back();
        }
    }
}

vector<vector<int>> print_combinations(vector <int> nums, int target)
{
    vector<int> temp;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    backtrack(res, temp, nums, target, 0);
    return res;
}


int main(int argc, char const *argv[])
{
    vector <int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;

    vector <int> candidates2 = {2, 5, 2, 2, 1, 2};
    int target2 = 5;

    auto res1 = print_combinations(candidates1, target1);
    auto res2 = print_combinations(candidates2, target2);

    print_vv(res1);
    print_vv(res2);

    return 0;
}

