// https://leetcode.com/problems/fruit-into-baskets/description

// You are visiting a farm that has a single row of fruit trees arranged from left to right. 
// The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. 
// There is no limit on the amount of fruit each basket can hold.

// Starting from any tree of your choice, you must pick exactly one fruit from every tree 

// (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

// Given the integer array fruits, return the maximum number of fruits you can pick.

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.

// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].

// Solution:

// The ask is to simply find longest contiguous subarray of 2 distinct elements
// We can use a variable sized sliding window to do this.
// Use a map to keep track of sizes
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0, max_fruits = 0;
        unordered_map<int, int> mp;
        int n = fruits.size();
        
        for(j=0; j<n; j++) {
            
            mp[fruits[j]] += 1;

            // cleanup from the left
            if(mp.size() > 2) {
                while(mp.size() > 2) {
                    mp[fruits[i]] -= 1;
                    if(mp[fruits[i]] == 0) {
                        mp.erase(fruits[i]);
                    }
                    i += 1;
                }
            }

            // maximum window size
            max_fruits = max(max_fruits, (j - i + 1));
        }

        return max_fruits;

    }
};

