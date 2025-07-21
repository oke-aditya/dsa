// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/

// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
// Here, freq(x) denotes the
// of the character x in word, and |y| denotes the absolute value of y.
// Return the minimum number of characters you need to delete to make word k-special.

// Example 1:

// Input: word = "aabcaba", k = 0

// Output: 3

// Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c".
// Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.

#include <climits>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for(auto ch: word) {
            mp[ch] += 1;
        }

        int min_del = INT_MAX;

        for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
            int freq = itr->second;

            // for this freq, let's try the ans
            int cnt = 0;

            for(auto itr2=mp.begin(); itr2!=mp.end(); itr2++) {
                int other_freq = itr2->second;

                // if this freq is greater than other
                // we may as well erase the other
                if(freq > other_freq) {
                    cnt += other_freq;
                } 

                // even after adding K extra to other freq it is greater
                // we need to subtract the portion
                else if(freq + k < other_freq ) {
                    cnt += other_freq - (freq + k);
                }

                // we aren't writing good cases
                // where freq + k is within limits of other freq
                // those don't add to cnt

            }
            min_del = min(min_del, cnt);
        }
        return min_del;

    }
};

