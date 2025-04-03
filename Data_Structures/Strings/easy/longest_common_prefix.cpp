// https://leetcode.com/problems/longest-common-prefix/description/

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.


// Approach

// The idea is to first iterate over the indices.
// Check if that index falls within the string.
// Test the first character of string with other strings
// if it does match all, add to result
// Else break the loops as the test character is not matching in one of the string.



#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int idx = 0;
            string res = "";
            bool fg = false;
    
            for(idx=0; idx<=200; idx++) {   
                if(idx < strs[0].size()) {
                    char chk = strs[0][idx];
                    for(auto str: strs) {
                        if(str[idx] != chk) {
                            fg = true;
                            break;
                        }
                    }
    
                    if(fg == true) {
                        break;
                    }
                    else {
                        res.push_back(chk);
                    }
                }
                
            }
    
            return res;
        }
    };
