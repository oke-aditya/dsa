// https://leetcode.com/problems/hand-of-straights/
// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Alice has some number of cards and she wants to rearrange the cards into groups so that 
// each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card 
// and an integer groupSize, return true if she can rearrange the cards, or false otherwise. 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

// The optimal approach is to build a map
// 
// 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // check if each group is of size groupSize
        int n = hand.size();
        if(n % groupSize)  {
            return false;
        }
        
        // Create frequency map
        map<int, int> mp;
        for(auto x: hand) {
            mp[x] += 1;
        }

        // Process each group starting from the smallest available card
        while(!mp.empty()) {
            int smallest = mp.begin()->first;
            
            // Try to form a group of groupSize consecutive numbers starting from smallest
            for(int i = 0; i < groupSize; i++) {
                if(mp.find(smallest + i) == mp.end()) {
                    return false;  // Card doesn't exist
                }
                
                mp[smallest + i] -= 1;
                
                // Remove card if count becomes 0
                if(mp[smallest + i] == 0) {
                    mp.erase(smallest + i);
                }
            }
        }

        return true;
    }
};


