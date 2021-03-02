// Given an array of distinct integers nums and a target integer target,
// return a list of all unique combinations of nums
// where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from nums an
// unlimited number of times. Two combinations are unique
// if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations
// that sum up to target is less than 150 combinations for the given input.

// Input: nums = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// Explanation:
// 2 and 3 are nums, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Input: nums = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Input: nums = [2], target = 1
// Output: []

// Input: nums = [1], target = 1
// Output: [[1]]

// Solution: -

// Printing combinations / subsequence. Always involves recursion.
// We have to recurse till we don't reach the target.
// We have 2 choices for each element. Either we can pick it or we can avoid it.
// 
// 
// 

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

// Pass the result by reference.
void backtrack(vector<vector<int>> &res, vector<int> temp, vector<int> nums, int target, int start)
{
    if(target < 0)
    {
        return;
    }
    // We have found one solution
    else if(target == 0)
    {
        res.push_back(temp);
    }
    else
    {
        for(int i=start; i<nums.size(); i++)
        {
            // We cann take the element.
            temp.push_back(nums[i]);

            // we have to reduce the target.
            // i -> Because we can re-use elements.
            backtrack(res, temp, nums, target - nums[i], i);

            // Important.
            // If we are not taking the element. We should remove the last element.
            // temp.erase(temp.end()-1);
            temp.pop_back();
        }
    }
}


vector<vector<int>> print_combination(vector <int> nums, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(res, temp, nums, target, 0);
    return res;

}

int main(int argc, char const *argv[])
{
    vector <int> candidates1 = {2, 3, 5};
    int target1 = 7;

    vector <int> candidates2 = {2, 3, 5};
    int target2 = 8;

    auto res1 = print_combination(candidates1, target1);
    auto res2 = print_combination(candidates2, target2);

    print_vv(res1);
    print_vv(res2);

    return 0;
}


