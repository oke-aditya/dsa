// Trapping Rain Water
// Given n non-negative integers representing an elevation map where
// the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is 
// represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include<bits/stdc++.h>
using namespace std;

// Solution: -
// A simple solution would be to keep a suffix array and prefix array.
// In suffix array, kee[ ]
// 

int trap_brute(vector<int>& height)
{


}

int trap_opt(vector<int> &height)
{

}

int main(int argc, char const *argv[])
{
    vector <int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trap_brute(v)<<endl;
    cout<<trap_opt(v)<<endl;

    return 0;
}

