// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

// You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
// Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, 
// return an empty array. And if there are multiple answers, return any of them.


// Example 1:

// Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
// Output: [[1,1,3],[3,4,5],[7,8,9]]

// Explanation:
// The difference between any two elements in each array is less than or equal to 2.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    void print_vv(vector<vector<int>> vv) {
        for(auto v: vv) {
            cout<<"[";
            for(auto x: v) {
                cout<<x<<" ";
            }
            cout<<"]";
        }
    }

    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        vector<int> temp;
        int i = 1;
        bool flag = true;

        for(auto x: nums) {
            if((i % 3)  == 0) {
                temp.push_back(x);
                res.push_back(temp);
                // if(temp[2] - temp[0] > k) {
                //     flag = false;
                //     break;
                // }
                temp.clear();
                
            }
            else {
                temp.push_back(x);
            }
            i += 1;
        }

        // print_vv(res);

        // bool flag = true;
        for(int i=0; i<res.size(); i++) {
            if(res[i][2] - res[i][0] > k) {
                flag = false;
                break;
            }
        }

        if(flag == false) {
            vector<vector<int>> res2;
            return res2;
        }

        else {
            return res;
        }


    }
};
