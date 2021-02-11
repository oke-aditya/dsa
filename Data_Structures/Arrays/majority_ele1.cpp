// Given an array nums of size n, return the majority element.
// 
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// 
// You may assume that the majority element always exists in the array.
// 
// Input: nums = [3,2,3]
// Output: 3
// 
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
// 
// 

#include<bits/stdc++.h>
using namespace std;

// Solution 1: -
// Use hashmap and store number of times a variable occurs.
// Again iterate over hashmap and print numbers that occur more than floor(n / 2) times.

int majority_ele_hm(vector<int> v)
{
    int n = v.size();
    unordered_map <int, int> mp;
    for(auto ele : v)
    {
        mp[ele] += 1;
    }

    for(auto itr=mp.begin(); itr != mp.end(); itr++)
    {
        if(itr->second > floor((v.size() / 2)))
        {
            return itr->first;
        }
    }
    return -1;
}

// Solution 2 :-
// Optimal Solution
// Keep a variable to mark count of number.
// if count = 0 we get a new candidate that can be majority element
// If number is same as condidate then increase the count.
// Finally return the candidate.


int majority_ele_opt(vector <int> v)
{
    // Moore's voting algorithm.
    int count = 0, candidate = 0;
    for(auto num: v)
    {
        if(count == 0)
        {
            candidate = num;
        }
        if(num == candidate)
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }
    return candidate;
}

int main(int argc, char const *argv[])
{
    vector <int> v = {2, 2, 1, 1, 1, 2, 2};
    int res = majority_ele_hm(v);
    cout<<res<<endl;
    int res2 = majority_ele_hm(v);
    cout<<res2<<endl;

    return 0;
}


