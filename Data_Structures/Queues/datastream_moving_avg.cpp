// https://leetcode.com/problems/moving-average-from-data-stream

// Description

// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// Implement the MovingAverage class:

//     MovingAverage(int size) Initializes the object with the size of the window size.
//     double next(int val) Returns the moving average of the last size values of the stream.

// Input
// ["MovingAverage", "next", "next", "next", "next"]
// [[3], [1], [10], [3], [5]]
// Output
// [null, 1.0, 5.5, 4.66667, 6.0]

// Explanation
// MovingAverage movingAverage = new MovingAverage(3);
// movingAverage.next(1); // return 1.0 = 1 / 1
// movingAverage.next(10); // return 5.5 = (1 + 10) / 2
// movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
// movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3

#include<vector>

using namespace std;

class MovingAverage {

    private:
        vector<int> data;
        int cnt = 0;
        int s = 0;

    public:
        MovingAverage(int size) {
            data.resize(size);
        }
    
        double next(int val) {
            // This line calculates the index i where the new value will be placed. 
            // Since the stream has a limited size, it uses the modulo operator (%) to cycle through the data array.
            int i = cnt % data.size();

            // This updates the sum s of the elements currently in the stream.
            s += val - data[i];

            // This stores the new value in the appropriate index in the data array.
            data[i] = val;

            ++cnt;
            // min(cnt, (int) data.size()) ensures that 
            // the denominator doesn't exceed the size of the data array. 
            // If the count cnt is smaller than the array size (meaning the moving average hasn’t yet reached its full capacity), 
            // it divides by cnt. Once the array is full, it divides by data.size() 
            // to compute the average over the last size elements
            return s * 1.0 / min(cnt, (int) data.size());
        }
         
};


