// https://cses.fi/problemset/task/1646

// Given an array of n integers, your task is to process q queries of the form: what is the sum of values in range [a,b]?
// Input

// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.

// Finally, there are q lines describing the queries. Each line has two integers a and b: what is the sum of values in range [a,b]?

// Output
// Print the result of each query.

// Input:

// 8 4
// 3 2 4 5 1 1 5 3
// 2 4
// 5 6
// 1 8
// 3 3

// Output:

// 11
// 2
// 24
// 4


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

int main(int argc, char const *argv[])
{

    // first you get n and q
    int n, q, num;;
    cin>>n>>q;

    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        nums.push_back(num);
    }
    
    // compute the prefix sum for these, so that we can answer queries v fast.

    // size n+1
    vector<long long> prefix_sum(n + 1);

    for(int i=1; i<=n; i++)
    {
        // compute the prefix sum array.
        prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
    }

    // we can print the prefix sum to get an idea.
    // print_v(prefix_sum);

    // now answer the q eueries

    // note queries are 1 based


    int left, right;
    while(q--)
    {
        cin>>left;
        cin>>right;
        cout<<prefix_sum[right] - prefix_sum[left-1]<<"\n";
    }

    return 0;
}



