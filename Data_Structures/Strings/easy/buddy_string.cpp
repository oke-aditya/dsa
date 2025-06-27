// https://leetcode.com/problems/buddy-strings/

// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
// For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

// Example 1:

// Input: s = "ab", goal = "ba"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

// Example 2:

// Input: s = "ab", goal = "ab"
// Output: false
// Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // basic check
        if(s.size() != goal.size()) {
            return false;
        }

        // find how many characters they differ
        int differ = 0, i = 0, j = 0, m = s.size(), n = goal.size(), has_any_even = false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        // cout<<m<<endl;
        // cout<<n<<endl;

        while(i<m && j<n) {
            if(s[i] != goal[j]) {
                differ += 1;
            }
            mp1[s[i]] += 1;
            mp2[goal[j]] += 1;

            if(mp1[s[i]]%2 == 0 && mp2[goal[j]] % 2 == 0) {
                has_any_even = true;
            }

            i += 1;
            j += 1;
        }


        // cout<<differ<<endl;
        // cout<<has_any_even<<endl;

        // more than one swap would be needed.
        if(differ > 2) {
            return false;
        }

        // differ exactly at 1 index
        if(differ == 2 && mp1 == mp2) {
            return true;
        }

        // these don't differ, look same
        if(differ == 0 && has_any_even) {
            return true;
        }

        return false;


    }
};