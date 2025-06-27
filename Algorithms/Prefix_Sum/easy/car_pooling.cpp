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
        // from and to are pretty small
        // store from and to
        vector<int> prefix_sum(1001, 0);

        // just allocate the trips
        for(auto trip: trips) {
            int start = trip[1];
            int end = trip[2];
            int curr_cap = trip[0];

            for(int i=start; i<end; i++) {
                prefix_sum[i] += curr_cap; 
            }
        }
        
        // if any trip would be overfull
        for(auto cap: prefix_sum) {
            if(cap > capacity) {
                return false;
            }
        }

        return true;

    }
};

