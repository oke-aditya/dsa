// https://leetcode.com/problems/permutations/

// Given an array nums of distinct integers,
// return all the possible permutations.
// You can return the answer in any order.

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Input: nums = [1]
// Output: [[1]]

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
               vector<int> nums, int start=0)
{
    // Push if we have permutated all the elements.
    if(temp.size() == nums.size())
    {
        res.push_back(temp);
    }
    else
    {
        
        for(int i=start; i<nums.size(); i++)
        {
            // If it exists. We can avoid.
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end())
            {
                continue;
            }

            temp.push_back(nums[i]);
            backtrack(res, temp, nums);

            // Don't inlcude. Remove it
            temp.pop_back();
        }
    }
}               

vector<vector<int>> print_perms(vector<int> nums)
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
    vector<int> v2 = {0, 1};

    auto res1 = print_perms(v1);
    auto res2 = print_perms(v2);

    print_vv(res1);
    print_vv(res2);

    return 0;
}


