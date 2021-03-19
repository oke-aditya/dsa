// https://leetcode.com/problems/permutations/
// Given a collection of numbers, nums, that might contain duplicates,
// return all possible unique permutations in any order.

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

#include<bits/stdc++.h>

using namespace std;

void print_vv(vector<vector<int>> vv)
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



vector<vector<int>> print_perms(vector <int> nums)
{
    vector<vector<int>> res;
    vector <int> temp;
    sort(res.begin(), res.end());

    backtrack(res, temp, nums, 0)

    return res;
}

int main(int argc, char const *argv[])
{
    vector <int> nums = {1, 1, 2};

    auto res = print_perms(nums);

    print_vv(res);

    return 0;
}

