// We use two data structures to implement an LRU Cache.
// Queue which is implemented using a doubly linked list.
// The maximum size of the queue will be equal to the
// total number of frames available (cache size).
// The most recently used pages will be near front end and least recently pages
// will be near the rear end.

// A Hash with page number as key and address of the corresponding queue node as
// value.

// When a page is referenced, the required page may be in the memory.
// If it is in the memory, we need to detach the node of the list and bring it
// to the front of the queue. If the required page is not in memory, we bring
// that in memory. In simple words, we add a new node to the front of the queue
// and update the corresponding node address in the hash. If the queue is full,
// i.e. all the frames are full, we remove a node from the rear of the queue,
// and add the new node to the front of the queue.

// https://leetcode.com/problems/lru-cache/
// Design a data structure that follows the constraints of a Least Recently Used
// (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.

// int get(int key) Return the value of the key if the key exists, otherwise
// return -1.

// void put(int key, int value) Update the value of the key if the key exists.

// Otherwise, add the key-value pair to the cache. If the number of keys exceeds
// the capacity from this operation, evict the least recently used key.

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
 public:
  int cacheSize;
  map<int, int> m;
  deque<int> dq;

  LRUCache(int capacity) {
    m.clear();
    dq.clear();
    cacheSize = capacity;
  }

  int get(int key) {
    // not found
    if (m.find(key) == m.end()) {
      return -1;
    } else {
      // found
      deque<int>::iterator it = dq.begin();
      while (*it != key) {
        it++;
      }

      // update queue: update it to most recent used value
      dq.erase(it);
      dq.push_front(key);

      return m[key];
    }
  }

  void put(int key, int value) {
    // not present in cache
    if (m.find(key) == m.end()) {
      // check if cache is full
      if (cacheSize == dq.size()) {
        int last = dq.back();
        dq.pop_back();
        m.erase(last);
      }
    } else {
      // present in cache, remove it from queue and map
      deque<int>::iterator it = dq.begin();
      while (*it != key) {
        it++;
      }

      dq.erase(it);
      m.erase(key);
    }

    // update the cache
    dq.push_front(key);
    m[key] = value;
  }
};

int main(int argc, char const *argv[]) { return 0; }
