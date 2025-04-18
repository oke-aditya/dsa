// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1

// Given an array arr of size N, the task is to remove or delete the minimum number of elements from the array so that 
// when the remaining elements are placed in the same sequence order form an increasing sorted sequence.

// Example 1:

// Input: N = 5, arr[] = {5, 6, 1, 7, 4}
// Output: 2
// Explanation: Removing 1 and 4
// leaves the remaining sequence order as
// 5 6 7 which is a sorted sequence.

// Basically, same as LIS, but we need to delete non LIS values
// Items to delete = Len(array) - Length of LIS


#include<vector>
#include<algorithm>

using namespace std;


class Solution{
	public:
	int minDeletions(int arr[], int n) {
	    // find LIS
	    vector<int> dp(n, 1);
	    
	    for(int i=n-1; i>=0; i--) {
	        for(int j=n-1; j>i; j--) {
	            
	           // update LIS of 
	           if(arr[i] < arr[j]) {
	               dp[i] = max(dp[i], 1 + dp[j]);
	           }
	        }
	    }
	    
	    return n - *max_element(begin(dp), end(dp));
	    
	    
	} 
};
