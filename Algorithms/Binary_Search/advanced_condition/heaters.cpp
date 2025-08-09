// https://leetcode.com/problems/heaters/description/

// Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
// Every house can be warmed, as long as the house is within the heater's warm radius range. 
// Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of 
// heaters so that those heaters could cover all houses.
// Notice that all the heaters follow your radius standard, and the warm radius will the same.

// Example 1:

// Input: houses = [1,2,3], heaters = [2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

// Example 2:

// Input: houses = [1,2,3,4], heaters = [1,4]
// Output: 1
// Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.

// Example 3:

// Input: houses = [1,5], heaters = [2]
// Output: 3

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

    // for this radius check if it's possible or not
    bool is_possible(vector<int> &houses, vector<int> &heaters, int cand) {
        int i=0, j=0;
        // go through all the houses.
        // check if each house is within the radius of heater
        int n = houses.size();
        int m = heaters.size();

        while(i<n) {
            // no heater left to heat house
            if(j == m) {
                return false;
            }

            int l = heaters[j] - cand;
            int r = heaters[j] + cand;

            // this heater heats the house
            if(l <= houses[i] && r >= houses[i]) {
                i += 1;
            }

            else {
                j += 1;
            }

        }
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(begin(houses), end(houses));
        sort(begin(heaters), end(heaters));
        
        // initialize radius
        int left = 0;
        int right = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
        int radius = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(is_possible(houses, heaters, mid)) {
                radius = mid;
                // we can do better
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return radius;


    }
};
