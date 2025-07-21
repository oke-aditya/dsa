// https://leetcode.com/problems/bus-routes/

// You are given an array routes representing bus routes where routes[i] is a 
// bus route that the ith bus repeats forever.
// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in 
// the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), 
// and you want to go to the bus stop target. You can travel between bus stops by buses only.
// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

// Example 1:

// Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
// Output: 2
// Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

// Example 2:

// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
// Output: -1

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // stops to bus, route as graph node
        // build a graph
        // then do a BFS

        // no need to take a bus
        if(source == target)
            return 0;

        unordered_map<int, vector<int>> stop_to_buses;


        for(int busid=0; busid<routes.size(); busid++) {
            for(int stop: routes[busid]) {
                stop_to_buses[stop].push_back(busid);
            }
        }

        // no path between source to dest
        if(stop_to_buses.find(source) == stop_to_buses.end() || stop_to_buses.find(target) == stop_to_buses.end())
            return -1;

        queue<int> q;
        unordered_set<int> buses_taken;
        unordered_set<int> stops_visited;
        int res = 0;

        q.push(source);

        while(!q.empty()) {

            // each step of BFS means we needed one more stop
            res += 1;
            int stop_to_process = q.size();
            
            while(stop_to_process--) {
                int current_stop = q.front();
                q.pop();

                for(int busid: stop_to_buses[current_stop]) {
                    if(!buses_taken.count(busid)) {
                        buses_taken.insert(busid);
                        for(int next_stop: routes[busid]) {
                            if(!stops_visited.count(next_stop)) {
                                if(next_stop == target) {
                                    return res;
                                }
                            }
                            q.push(next_stop);
                            stops_visited.insert(next_stop);
                        }
                    }   
                }
            }
        }
        
        return -1;

    }
};
