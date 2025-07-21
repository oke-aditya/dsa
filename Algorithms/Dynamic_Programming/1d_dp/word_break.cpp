// https://leetcode.com/problems/word-break/

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a 
// space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Solution:
// We just need 1 state, what have we traversed till now, and was that in word dict
// if that was in the word dict, then we should evaluate the next thing
// brute force would be to keep re-creating the string on every trversal.
// instead of just store that in dp state.


#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int n = s.size();
    
            // captures the state if the word can be broken
            // we use n+1 and ignore 0th state
            vector<bool> dp(n+1, false);
    
            // 0th state is "" which is true
            dp[0] = true;
    
            // 1 to n
            for(int i=1; i<=n; i++) {
                for(int j=i-1; j>=0; j--) {
                    // the jth state is actually achievable
                    if(dp[j]) {
                        // the substring is i to j-i length
                        string sub = s.substr(j, i-j);
                        if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
    
            return dp[n];
    
        }
    };

