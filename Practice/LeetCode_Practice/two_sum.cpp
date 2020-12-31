// Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1]

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Time complexity Expected = O(n)

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

void print_mp(unordered_map<int, int> m)
{
    for(auto i=m.begin(); i!= m.end(); i++)
    {
        cout<<i->first<<" "<<i->second<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void solve(vector <int> arr, int money) {
    // Complete this function
    int first_pick = 0;
    int second_pick;
    unordered_map<int,int> cost;

    for(int i=0;i<arr.size();i++)
    {
        second_pick = i;
        int chk = money-arr[i];

        if(cost.count(chk))
        {
            first_pick = cost[chk];
            cout<<first_pick+1<<" "<<second_pick+1<<endl;
            return;
        }
        cost[arr[i]]=i;
    }
}

int main(int argc, char const *argv[])
{
    vector <int> nums = {3, 2, 4};

    int target = 6;

    solve(nums, target);

    return 0;
}


