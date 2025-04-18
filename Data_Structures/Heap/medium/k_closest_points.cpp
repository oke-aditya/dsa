// https://leetcode.com/problems/k-closest-points-to-origin/

// We have a list of points on the plane.  Find the K closest points to the
// origin (0, 0).

// (Here, the distance between two points on a plane is the Euclidean distance.)

// You may return the answer in any order.  The answer is guaranteed to be
// unique (except for the order that it is in.)

// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just
// [[-2,2]].

// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)

// Solution: -
// Caclulate distance for each element. which will be (v[i][0] * v[i][0] +
// v[i][1] * v[i][1]) Add these values to a heap, maintaining distance as key
// and points. If heap is greater than k elements, pop items from heap. Return
// remaining items in heap. Use a Max heap here.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          // find distance from origin for each point, ignore the sqrt
          // points with minimum distance are needed
          // store in a maxheap.
          // store as {distance, {x, y}}
          
          priority_queue<pair<int, pair<int, int>>> maxh;
  
          for(auto point: points) {
              int x = point[0];
              int y = point[1];
  
              int distance = (x * x + y * y);
              maxh.push(make_pair(distance, make_pair(x, y)));
  
              if(maxh.size() > k) {
                  maxh.pop();
              }
          }
  
          // cout<<"D";
  
          // result vector
          vector<vector<int>> res;
          while(!maxh.empty()) {
              int x = maxh.top().second.first;
              int y = maxh.top().second.second;
              maxh.pop();
              res.push_back(vector<int> {x, y});
          }
  
          return res;
  
      }
  };
  