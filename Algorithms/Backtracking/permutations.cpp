// Permutations
// https://leetcode.com/problems/permutations/description/

// Given an array nums of distinct integers, return all the possible
// permutations
// You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

// Idea here is to swap and backtrack
// Use a set cache to drop duplicates
// First write the backtrack solution then add set cache


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




// Adding cache is optional that will only limit the backtrack for more efficient
// Note all are passed via pass by reference
void backtrack(vector<int> &nums, int begin, vector<vector<int>> &res)
{

    // Base case if when we reach last in permute, begin reaches n-1
    if (begin == nums.size() - 1) {
        // One perumte cases
        res.push_back(nums);
        return;
    }
    // Permute is swapping nums in all combinations.
    // Standard for loop to iterate over every element

    unordered_set<int> cache;

    for(int i=begin; i<nums.size(); i++)
    {
        // it is found in cache. set only has 1.
        if(cache.count(nums[i]) == 1)
        {
            cout<<"hit the cache";
            continue;
        }

        cache.insert(nums[i]);

        swap(nums[begin], nums[i]);
        // Recurse it from next step
        backtrack(nums, begin+1, res);
        // Reverse the o/p
        swap(nums[begin], nums[i]);

        // cache.pop_back();

    }

}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> res;
    // vector<int> cache;

    backtrack(nums, 0, res);

    return res;
        
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 4};
    auto ret = permute(nums);
    print_vv(ret);
    return 0;
}


