// Given an array arr[] of size N and an integer K.
// Find the maximum for each and every contiguous subarray of size K.
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
// https://www.interviewbit.com/problems/sliding-window-maximum/#
// https://leetcode.com/problems/sliding-window-maximum/

// Example:
// Input 1:
//     A = [1, 3, -1, -3, 5, 3, 6, 7]
//     k = 3
// Output 1:
//     C = [3, 3, 5, 5, 6, 7]

#include <bits/stdc++.h>
using namespace std;

// Algorithm:

// Create a deque to store k elements.
// Run a loop and insert first k elements in the deque.
// Before inserting the element, check if the element at the back of
// the queue is smaller than the current element ,
// if it is so remove the element from the back of the deque,
// until all elements left in the deque are greater than the current element.
// Then insert the current element, at the back of the deque.
// Now, run a loop from k to end of the array.
// Print the front element of the deque.
// Remove the element from the front of the queue if they are out of the current
// window. Insert the next element in the deque. Before inserting the element,
// check if the element at the back of the queue is
// smaller than the current element , if it is so remove the element
// from the back of the deque, until all elements left
// in the deque are greater than the current element.
// Then insert the current element, at the back of the deque.
// Print the maximum element of the last window.

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

vector<int> print_k_max(vector<int> v, int k) {
  vector<int> res;
  deque<int> q;

  int n = v.size();

  // Process first window
  for (int j = 0; j < k; j++) {
    // For every element, previous smaller elements are useless.
    while ((!q.empty()) && v[j] >= v[q.back()]) {
      // Remove from the rear end of queue
      q.pop_back();
    }
    // Add this index to start of queue.
    q.push_back(j);
  }
  res.push_back(v[q.front()]);

  // Process rest of the elements
  int i = 0;
  for (int j = k; j < n; j++) {
    // Remove elements which are out of the current window (undo step)
    while ((!q.empty()) && q.front() < i + 1) {
      q.pop_front();
    }
    // Again remove all elements which are smaller to current j.
    while ((!q.empty()) && v[j] >= v[q.back()]) {
      q.pop_back();
    }
    // Add this index to end of queue.
    q.push_back(j);
    i += 1;
    res.push_back(v[q.front()]);
  }
  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  auto res = print_k_max(v, k);

  print_v(res);
  cout << endl;
  return 0;
}
