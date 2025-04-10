// https://leetcode.com/problems/stock-price-fluctuation/description/

// You are given a stream of records about a particular stock. 
// Each record contains a timestamp and the corresponding price of the stock at that timestamp.

// Unfortunately due to the volatile nature of the stock market, the records do not come in order. 
// Even worse, some records may be incorrect. Another record with the same timestamp may appear later 
// in the stream correcting the price of the previous wrong record.

#include<bits/stdc++.h>

using namespace std;

// Design an algorithm that:

//     Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
//     Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
//     Finds the maximum price the stock has been based on the current records.
//     Finds the minimum price the stock has been based on the current records.

// Implement the StockPrice class:

//     StockPrice() Initializes the object with no price records.
//     void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
//     int current() Returns the latest price of the stock.
//     int maximum() Returns the maximum price of the stock.
//     int minimum() Returns the minimum price of the stock.

// Example 1:

// Input
// ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
// [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
// Output
// [null, null, null, 5, 10, null, 5, null, 2]

// solution:
// the 


class StockPrice {
    public:
    
        // easy to get max price of stock
        // pair has <price, timestamp>
        priority_queue<pair<int, int>> maxh;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    
        // we will store <tmestamp, price>
        // use this to update the heaps
        unordered_map<int,int> mp;
    
        // save current price and time
        int current_price = 0;
        int current_time = 0;
    
        StockPrice() {
            
        }
        
        void update(int timestamp, int price) {
            // we will push to both the heaps
            // first update the map
            mp[timestamp] = price;
    
            maxh.push({price, timestamp});
            minh.push({price, timestamp});
    
            // update the current one
            if(timestamp >= current_time) {
                current_time = timestamp;
                current_price = price;
            }
    
            // update the max heap
            // check for the price on timestamp, if it is not matching heap price.
            while(mp[maxh.top().second] != maxh.top().first) {
                maxh.pop();
            }
    
            // update the max heap
            // check for the price on timestamp, if it is not matching heap price.
            while(mp[minh.top().second] != minh.top().first) {
                minh.pop();
            }
        }
        
        // max time stamp based price
        int current() {
            return current_price;
        }
        
        int maximum() {
            return maxh.top().first;
        }
        
        int minimum() {
            return minh.top().first;
        }
    };
    
    /**
     * Your StockPrice object will be instantiated and called as such:
     * StockPrice* obj = new StockPrice();
     * obj->update(timestamp,price);
     * int param_2 = obj->current();
     * int param_3 = obj->maximum();
     * int param_4 = obj->minimum();
     */
