// https://www.hackerrank.com/contests/startup-career-fair-challenge/challenges/scf-hard

// You are given an array/list ARR consisting of N integers. Your task is to find the length of the longest decreasing subsequence.
// A subsequence is a sequence of numbers obtained by deleting zero or more elements from the array/list, 
// keeping the relative positions of elements same as it was in the initial sequence. 
// A decreasing subsequence is a subsequence in which every element is strictly less than the previous number.

// Note:
// There can be more than one subsequences with the longest length.

// For example:-
// For the given array [5, 0, 3, 2, 9], the longest decreasing subsequence is of length 3, i.e. [5, 3, 2]

// Solution:
// This is same as LIS, just be careful on the condition.
// What is LDS of last element? it is 1.
// What is LDS of firt element, it is 3.
// We can compute LDS of 1st element using the right side of array. 
//



#include <algorithm>
#include<vector>
using namespace std;

int LDS(vector<int> arr){

    int n = arr.size();
    vector<int> dp(n, 1);

    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>i; j--) {
            // this condition is reversed here
            if(arr[j] < arr[i]) {
                // based on j we compute dp for i.
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(begin(dp), end(dp));

}


