// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Input: nums = [3,2,3]
// Output: [3]
// 
// 

#include<bits/stdc++.h>
using namespace std;

// Solution 1: -
// Use hashmap and store number of times a variable occurs.
// Again iterate over hashmap and print numbers that occur more than floor(n / 3) times.
// 

// Solution 2: -
// 
// Use an Extended version of Moore's voting algorithm
// Maintain two variables, and two counters. Both the variables keep track of counts.
// Iterate oever the array and increase counter if either number matches.
// Decrase both the counts if numbers don't match.

// Here since there can be more than onew answers.
// We have to re iterate and check if count is greater than n / 3.

void print_v(vector <int> v)
{
    for(auto ele : v)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

vector<int> maj_ele_hm(vector <int> v)
{
    int n = v.size();
    map<int, int> mp;
    vector <int> res;
    for(auto ele: v)
    {
        mp[ele] += 1;
    }

    for(auto itr=mp.begin(); itr != mp.end(); itr++)
    {
        if(itr->second > floor((n / 3)))
        {
            res.push_back(itr->first);
        }
    }
    return res;
}

vector<int> maj_ele_opt(vector <int> v)
{
    vector <int> res;

    int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0, i;

    int n = v.size();
    for(i=0; i<n; i++)
    {
        if(v[i] == candidate1)
        {
            count1 += 1;
        }
        else if(v[i] == candidate2)
        {
            count2 += 1;
        }
        else if (count1 == 0)
        {
            candidate1 = v[i];
            count1 = 1;
        }
        else if(count2 == 0)
        {
            candidate2 = v[i];
            count2 = 1;
        }
        else
        {
            count1 -= 1;
            count2 -= 1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(v[i] == candidate1)
        {
            count1 += 1;
        }
        else if(v[i] == candidate2)
        {
            count2 += 1;
        }
    }
    if(count1 > floor(n / 3))
    {
        res.push_back(candidate1);
    }
    else if(count2 > floor(n / 3))
    {
        res.push_back(candidate2);
    }

    return res;
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1, 1, 1, 3, 3, 2, 2, 2};
    
    auto res = maj_ele_hm(v);
    print_v(res);

    auto res2 = maj_ele_opt(v);
    print_v(res);

    return 0;
}

