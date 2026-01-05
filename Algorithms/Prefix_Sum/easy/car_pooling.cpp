// https://leetcode.com/problems/car-pooling/
// There is a car with capacity empty seats. 
// The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] 
// indicates that the ith trip has numPassengersi passengers and the locations to pick them up 
// and drop them off are fromi and toi respectively. The locations are given as the 
// number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all 
// passengers for all the given trips, or false otherwise.

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

// Example 2:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 1001;
        vector<int> prefix_sum(n+1, 0);

        for(auto trip: trips) {
            int c = trip[0];
            int left = trip[1];
            int right = trip[2];
            prefix_sum[left] += c;
            prefix_sum[right] -= c; 
        }

        for(int i=1; i<=n; i++) {
            prefix_sum[i] += prefix_sum[i-1];
        }

        for(int i=0; i<n; i++) {
            if(prefix_sum[i] > capacity) {
                return false;
            }
        }

        return true;

    }
};