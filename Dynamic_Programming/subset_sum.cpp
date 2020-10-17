// Given a set of non-negative integers, and a value sum,
// determine if there is a subset of the given set with sum equal to given sum.

#include<bits/stdc++.h>
using namespace std;

bool is_subeset_sum_rec(int set[], int sum, int n)
{
    // Base Cases
    if(sum == 0)
    {
        return true;
    }
    if(n == 0)
    {
        return false;
    }

    // If the last element is greater, then we have to leave it
    if(set[n-1] > sum)
    {
        return (is_subeset_sum_rec(set, sum, n-1));
    }
    else
    {
        return (is_subeset_sum_rec(set, sum, n-1) || is_subeset_sum_rec(set, sum-set[n - 1], n-1));
    }
}

int main(int argc, char const *argv[])
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    int n = sizeof(set) / sizeof(set[0]);

    if(is_subeset_sum_rec(set, sum, n))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    

    return 0;
}





