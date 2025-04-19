// https://leetcode.com/problems/minimum-window-substring/
// Given two strings s and t, return the minimum
// window in s which will contain all the characters in t.
// If there is no such window in s that covers
// all characters in t, return the empty string "".

// Note that If there is such a window, it is
// guaranteed that there will always be only one unique minimum window in s.

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

// Input: s = "a", t = "a"
// Output: "a"

#include<string>
#include<unordered_map>
#include<climits>
using namespace std;


string minWindow(string s, string t) {
    // slide the window keeping track of have and required;
    int i=0, j=0, n=s.size(); 
    // will keep track of required
    unordered_map<char, int> mp1;
    // will keep track of have
    unordered_map<char, int> mp2;
    int min_window_start = 0;
    int min_window_end = 0;
    int min_window_length = INT_MAX;

    for(char ch: t) {
        mp1[ch] += 1;
    }

    for(auto itr=mp1.begin(); itr!=mp1.end(); itr++) {
        mp2[itr->first] = 0;

    }

    int want = mp1.size();
    int have = 0;

    for(j=0; j<n; j++) {
        
        if(have < want) {
            if(mp2.find(s[j]) != mp2.end()) {
                mp2[s[j]] += 1;

                if(mp2[s[j]] == mp1[s[j]]) {
                    have += 1;
                }
            }
        }
        
        while(want == have) {
            if((j - i + 1) < min_window_length) {
                min_window_start = i;
                min_window_end = j;
                min_window_length = (j - i + 1);
            }
            
            if(mp2.find(s[i]) != mp2.end()) {
                mp2[s[i]] -= 1;
                
                if(mp2[s[i]] < mp1[s[i]]) {
                    have -= 1;
                }
            }
            i += 1;
        }
    
    }
    if (min_window_length == INT_MAX) {
        return "";
    }

    return s.substr(min_window_start, min_window_length);

}