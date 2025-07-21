// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

// You are given a 0-indexed array of strings words and a 2D array of integers
// queries.

// Each query queries[i] = [li, ri] asks us to find the number of strings
// present in the range li to ri (both inclusive) of words that start and end
// with a vowel. Return an array ans of size queries.length, where ans[i] is the
// answer to the ith query. Note that the vowel letters are 'a', 'e', 'i', 'o',
// and 'u'.

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:

    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
    bool start_ends_vowel(string s) {

        if(s.size() == 1) {
            return st.find(s[0]) != st.end();
        }

        else {
            return st.find(s[0]) != st.end() && st.find(s[s.size()-1]) != st.end();
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> res, prefix_sum(n+1, 0);

        for(int i=0; i<n; i++) {
            if(start_ends_vowel(words[i])) {
                prefix_sum[i+1] = prefix_sum[i] + 1;
            }
            else {
                prefix_sum[i+1] = prefix_sum[i];
            }
        }

        for(auto query: queries) {
            int L = query[0];
            int R = query[1];
            res.push_back(prefix_sum[R+1] - prefix_sum[L]);
        }

        // answer the queries
        return res;

    }
};
