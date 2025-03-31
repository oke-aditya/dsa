// https://leetcode.com/problems/longest-repeating-character-replacement/

// You are given a string s and an integer k. You can choose any character of 
// the string and change it to any other uppercase English character. 
// You can perform this operation at most k times.
// Return the length of the longest substring containing the same 
// letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Solution:
// Trick here is to find max value in the map and take it's difference to window size
// Consider this window and i j

// k = 1
//  AABABBA
//    i  j
// this is the valid answer, we need to flip the middle k
// here, we can see map would look like {'A': 1, 'B': 3}
// window size = j - i + 1  == 5 - 2 + 1 = 4
// Max value in the map is 3.
// so window - max(map) <= k 
// are good sequences
// above them are bad



#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    
        int find_max(unordered_map<int, int> &mp) {
            int max_v = 0;
            for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
                max_v = max(max_v, itr->second);
            }
            return max_v;
        }
    
        int characterReplacement(string s, int k) {
            // same logic but handle the replacement
    
            int i=0, j=0;
            unordered_map<int, int> mp;
            int n = s.size(), max_len = 0;
    
            for(j=0; j<n; j++) {
                mp[s[j]] += 1;
    
                // find max in the map?
                int max_v = find_max(mp);    
    
                // if the window size - max_v is less than / equal to k
                // we have a solution
                if((j - i + 1 - max_v) <= k) {
                    max_len = max(max_len, (j - i + 1));
                }
    
                // we would need to do cleanup from left
                else {
                    while((j - i + 1 - max_v) > k) {
                        mp[s[i]] -= 1;
                        if(mp[s[i]] == 0) {
                            mp.erase(s[i]);
                        }
                        i += 1;
                    }
                    // after cleaning if the condition is satisifed
                    max_len = max(max_len, (j - i + 1));
                }
            }
    
            return max_len;
    
        }
    };