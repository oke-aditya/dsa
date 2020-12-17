// Sort Array by Increasing Frequency
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
// If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

// Solution: -
// 1. Heap way
// Prepare a hash map, with key and value pairs
// Add one by one to the heap using values from map by frequency
// We need just to add elements to heap, use min heap so that minimum value is at top.


#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

// To compare and return in correct order
struct compare
{
    bool operator()(const pii &a, const pii &b)
    {
        if(a.first == b.second)
        {
            return a.second > a.first;
        }
        return a.first < b.first;
    }
};


void print_v(vector <int> v)
{
    for(auto x : v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

vector <int> freq_sort_heap(vector <int> v)
{
    // Create a hashmap and store the frequencies
    unordered_map <int, int> mp;
    for(int i=0; i<v.size(); i++)
    {
        mp[v[i]] += 1;
    }

    // Print the map once to check
    // for(auto i=mp.begin(); i!= mp.end(); i++)
    // {
    //     cout<<i->first<<" "<<i->second;
    //     cout<<endl;
    // }

    // Push to min heap
    priority_queue <pii, vector<pii>, greater<pii>> minh;

    // Add the comparator declaration
    // priority_queue <pii, vector<pii>, compare> minh2;

    // We need pair to put a map into heap.

    for(auto i=mp.begin(); i!= mp.end(); i++)
    {
        minh.push({i->second, i->first});
    }

    vector <int> res;

    while(!minh.empty())
    {
        int freq = minh.top().first;
        int ele = minh.top().second;

        for(int i=1; i<=freq; i++)
        {
            res.push_back(ele);
        }

        minh.pop();
    }

    return res;

}


int main(int argc, char const *argv[])
{
    vector <int> v {3,1,1,2,2,2};

    auto res = freq_sort_heap(v);

    print_v(res);

    // auto res = freq_sort_md(v);


    return 0;
}

