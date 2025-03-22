// https://leetcode.com/problems/gas-station/

// There are n gas stations along a circular route,
// where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of
// gas to travel from the ith station to its next (i + 1)th station.
// You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's
// index if you can travel around the circuit once in the clockwise direction,
// otherwise return -1. If there exists a solution, it is guaranteed to be
// unique

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3

// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
// 4 = 4 Travel to station 4. Your tank = 4 - 1 + 5 = 8 Travel to station 0.
// Your tank = 8 - 2 + 1 = 7 Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to
// station 3. Therefore, return 3 as the starting index.

/// Sol

// 1, if sum of gas is more than sum of cost, then there must be a solution.
// And the question guaranteed that the solution is unique(The first one I found
// is the right one). 2, The tank should never be negative, so restart whenever
// there is a negative number.

// If car starts at A and can not reach B. Any station between A and B
// can not reach B.(B is the first station that A can not reach.)

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int total = 0;
  int n = gas.size();
  for (int i = 0; i < n; i++) {
    total += gas[i] - cost[i];
  }
  if (total < 0) {
    return -1;
  }

  // find out where to start
  int tank = 0;
  int start = 0;
  for (int i = 0; i < n; i++) {
    tank += gas[i] - cost[i];
    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }
  return start;
}
