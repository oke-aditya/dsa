// https://binarysearch.com/problems/Sort-by-Frequency-and-Value

// Given a list of integers nums, order nums by frequency, with most frequent
// values coming first.
// If there's a tie in frequency, higher
// valued numbers should come first.
// Since 1 occurs most frequently (4 times) they come first.
// 5 and 2 are then tied in terms of frequency (both 3 times) but 5 has higher value so it comes second.

// Solution 1 (Naive): -
// Maintain an ordered map, each containing number and frequency.
// Traverse throught the map. find number with max frequency and add it to result.
// Delete that key form map, repeat.


// Solution 2 : -
// Implement custom sorting based on frequency.
// we can dump the map into a vector of pairs, and implement the custom sort there.

#include<bits/stdc++.h>
using namespace std;

void print_v(vector<int> v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


// Custom comparator for freq
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    // If freq is same
    if(p1.second == p2.second)
    {
        // Check if element is greater.
        return (p1.first > p2.first);
    }
    return (p1.second > p2.second);
}


vector <int> solve(vector <int> &nums)
{
    map<int, int> mp;
    for(auto n: nums)
    {
        mp[n] += 1;
    }

    // Store element and frequency.
    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);

    vector<int> res;

    for(int i=0; i<v.size(); i++)
    {
        // Get the second and first
        int ele = v[i].first;
        int freq = v[i].second;
        
        // Push element freq no of timees.
        for(int j=0; j<freq; j++)
        {
            res.push_back(ele);
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    vector <int> nums {1, 1, 5, 5, 5, 2, 2, 2, 1, 1};
    print_v(nums);

    return 0;
}


