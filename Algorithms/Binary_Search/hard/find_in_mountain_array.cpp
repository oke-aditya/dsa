// https://leetcode.com/problems/find-in-mountain-array/description/

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
//     arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//     arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
// If such an index does not exist, return -1.

// You cannot access the mountain array directly. 
// You may only access the array using a MountainArray interface:

// MountainArray.get(k) returns the element of the array at index k (0-indexed).
// MountainArray.length() returns the length of the array.

// Example 1:

// Input: mountainArr = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

// Example 2:

// Input: mountainArr = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1.


#include<iostream>
#include<climits>

using namespace std;

 // This is the MountainArray's API interface.
 // You should not implement it, or speculate about its implementation
 class MountainArray {
   public:
     int get(int index);
     int length();
 };
 
 class Solution {
    public:
    
        int bin_search(int left, int right, MountainArray &mountainArr, int target, bool ascending) {
            int idx = -1;
    
            while(left <= right) {
                int mid = left + (right - left) / 2;
                int mid_element = mountainArr.get(mid);
    
                // this array cannot have more than one occurence of it
                // in case it does, we will need to further search left
                if(mid_element == target) {
                    return mid;
                }
    
                else if(mid_element < target) {
                    if(ascending) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                    
                }
    
                else {
                    if(ascending) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                    
                }
            }
    
            return idx;
        }
    
        int find_peak(int left, int right, MountainArray &mountainArr) {
            int ans = -1, left_element, right_element, n = mountainArr.length();
            
            while(left <= right) {
                int mid = left + (right - left) / 2;
                
                // edge case if 0, assume left is smaller
                if(mid == 0) {
                    left_element = -1;
                }
                else {
                    left_element = mountainArr.get(mid-1);
                }
    
                if(mid == n-1) {
                    right_element = INT_MAX;
                }
                else {
                    right_element = mountainArr.get(mid+1);
                }
    
                int mid_element = mountainArr.get(mid);
    
    
                if((mid_element > left_element) && (mid_element > right_element)) {
                    return mid;
                }
    
                // search right
                else if((mid_element > left_element) && (mid_element < right_element)) {
                    left = mid + 1;
                }
    
                else {
                    right = mid - 1;
                }
            }
    
            return ans;
        }
    
    
        int findInMountainArray(int target, MountainArray &mountainArr) {
            // this is triple binary search
            // find the peak.
            // binary search left, if found good
            // binary search right
            // else return -1
    
            int left = 0;
            // n is atleast 3
            // mid will not be 0
            int n = mountainArr.length();
            int right = n - 1;
            int ans = -1;
    
            int peak_idx = find_peak(0, right, mountainArr);
            cout<<" pindex: "<<peak_idx<<endl;
    
            // binary_search left;
            // binary_search right;
    
            int left_idx = bin_search(0, peak_idx, mountainArr, target, true);
            int right_idx = bin_search(peak_idx+1, right, mountainArr, target, false);
    
            if(left_idx != -1){
                return left_idx;
            }
    
            else if(right_idx != -1) {
                return right_idx;
            }
    
            else {
                return -1;
            }
    
            return ans;
    
        }
    };


