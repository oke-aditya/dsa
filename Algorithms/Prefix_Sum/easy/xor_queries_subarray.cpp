// // https://leetcode.com/problems/xor-queries-of-a-subarray/description/

// You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

// For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

// Return an array answer where answer[i] is the answer to the ith query.

// Example 1:

// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
// Output: [2,7,14,8] 
// Explanation: 
// The binary representation of the elements in the array are:
// 1 = 0001 
// 3 = 0011 
// 4 = 0100 
// 8 = 1000 
// The XOR values for queries are:
// [0,1] = 1 xor 3 = 2 
// [1,2] = 3 xor 4 = 7 
// [0,3] = 1 xor 3 xor 4 xor 8 = 14 
// [3,3] = 8

#include<bits/stdc++.h>

using namespace std;


vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
{
    // here we will create a prefix sum of xor

    int n = arr.size();
    vector<int> prefix_sum(n + 1);

    // now compute xor to get this populated

    for(int i=1; i<=n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] ^ arr[i-1];
    }

    for(int i=0; i<=n; i++)
    {
        cout<<prefix_sum[i]<<" ";
    }

    vector<int> res;

    // now efficiently answer the queries
    for(auto q : queries)
    {
        // answer each of these with prefix sum knowledge
        int left = q[0];
        int right = q[1];
        res.push_back(prefix_sum[left] ^ prefix_sum[right+1]);
    }

    return res;
}

