// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

// You need to return the number of important reverse pairs in the given array.

// Input: [1,3,2,3,1]
// Output: 2

// Input: [2,4,3,5,1]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

int reverse_brute(vector<int> v)
{
    int n = v.size(), count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(v[i] > (2 * v[j]))
            {
                count += 1;
            }
        }
    }
    return count;
}


int main(int argc, char const *argv[])
{
    vector <int> v1 = {1, 3, 2, 3, 1};

    cout<<reverse_brute(v1)<<endl;

    vector <int> v2 = {2, 4, 3, 5, 1};

    cout<<reverse_brute(v2)<<endl;
    
    return 0;
}
