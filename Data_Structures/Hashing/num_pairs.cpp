// Given an array of integers nums.

// A pair (i,j) is called good if nums[i] == nums[j] and i < j.

// Return the number of good pairs.

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

// Solution

// We can just count each value. Then, n elements with the same value can form n * (n - 1) / 2 pairs.


#include<bits/stdc++.h>
using namespace std;

int num_ident_pairs(vector <int> v)
{
    int cnt[101] = {}, res = 0;

    for(int ele: v)
    {
        res += cnt[ele];
        cnt[ele] += 1;
    }

    return res;

}


int main(int argc, char const *argv[])
{
    vector <int> v1 = {1, 2, 3, 1, 1, 3};
    vector <int> v2 = {1, 1, 1, 1};

    int res1 = num_ident_pairs(v1);
    int res2 = num_ident_pairs(v2);

    cout<<res1<<endl;
    cout<<res2<<endl;

    
    return 0;
}

