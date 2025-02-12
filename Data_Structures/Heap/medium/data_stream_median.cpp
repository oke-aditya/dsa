// https://leetcode.com/problems/find-median-from-data-stream/

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

//     For example, for arr = [2,3,4], the median is 3.
//     For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

// Implement the MedianFinder class:

//     MedianFinder() initializes the MedianFinder object.
//     void addNum(int num) adds the integer num from the data stream to the data structure.
//     double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

 
 // folow up

//  1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?

// We can maintain an integer array of length 100 to store the count of each number along with a total count. Then, we can iterate over the array to find the middle value to get our median.

// Time and space complexity would be O(100) = O(1).

// 2. If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

// In this case, we need an integer array of length 100 and a hashmap for these numbers that are not in [0,100].


/// Solution: -

// Maintain 2 heaps
// Min heap and max heap
// balance these 2 to have difference of 1 element length
// avg of max value of min heap and min value of min heap will be median

// https://leetcode.com/problems/find-median-from-data-stream/solutions/1048192/c-easy-understandable-two-heaps-intuitive-solution-o-logn-add-o-1-find/

// The left heap is containing elements in decreasing order (Max to Min) and right heap is
//  in increasing order (Min to Max) but all the elements are greater than the left heap elements. 
//  We start pushing the elements in left heap and try to balance it everytime by comparing with 
//  the new elements and with heap size and accordingly put it into the right heap.

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:

    // left 
    priority_queue<int, vector<int>, greater<int>> minh;

    // right 
    priority_queue<int> maxh;
    

    MedianFinder() {
  
    }
    
    void addNum(int num) {

        if(maxh.empty() or maxh.top() > num)
        {
            maxh.push(num);
        }

        else
        {
            minh.push(num);
        }

        if(maxh.size() > minh.size() + 1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }

        else if(minh.size() > maxh.size() + 1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size() == maxh.size())
        {
            if(minh.size() == 0)
            {
                return 0;
            }
            else 
            {
                double avg = (minh.top() + maxh.top()) / 2.0;
                return avg;
            }
        }

        else
        {
            if(minh.size() > maxh.size())
            {
                return minh.top();
                
            }
            else
            {
                return maxh.top();
            }
        }
    }
};
