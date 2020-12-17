// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Solution: -
// We want k frequent numbers. numbers whose frequency is maximum
// Create a hash map which will store number and frequency of number.
// One by one add the hashmap values to the min heap till k.
// Pop values after k insertions.
// Heap will have top k answers stored.

#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

vector<int> k_freq(vector<int> v, int k)
{
    // Create a hashmap
    unordered_map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]] += 1;
    }

    // for (auto i = mp.begin(); i != mp.end(); i++)
    // {
    //     cout<<i->first<<" "<<i->second<<" ";
    //     cout<<endl;
    // }

    // Now create a min heap
    priority_queue<pii, vector<pii>, greater<pii>> minh;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        minh.push({i->second, i->first});
        if (minh.size() > k)
        {
            minh.pop();
        }
    }

    // Now store the answer one by one in result
    vector<int> res;

    while (!minh.empty())
    {
        res.push_back(minh.top().second);
        minh.pop();
    }

    return res;
}

void print_v(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 1, 1, 2, 2, 3};
    int k = 2;

    auto res = k_freq(v, k);

    print_v(res);

    return 0;
}
