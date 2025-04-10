// https://leetcode.com/problems/online-stock-span/description/
// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

//     For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
//     Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

// Implement the StockSpanner class:

//     StockSpanner() Initializes the object of the class.
//     int next(int price) Returns the span of the stock's price given that today's price is price.

 

// Example 1:

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]


// Solution
// Brute force Two Stacks, TLE on test cases 10**4
// We maintain two stacks, one to keep track of prices that are > 
// one to keep track track of prices that would be popped

#include <stack>
using namespace std;

class StockSpannerBrute {
  public:
      stack<int> stk;
      stack<int> stk2;
      
      StockSpannerBrute() {
      }
      
      int next(int price) {
          int count = 1;
          while(!stk.empty() && stk.top() <= price) {
              stk2.push(stk.top());
              stk.pop();
              count += 1;
          }
  
          while(!stk2.empty()) {
              stk.push(stk2.top());
              stk2.pop();
          }
  
          stk.push(price);
  
          return count;
      }
  };
  
// optimal solution
// use stack as pair<int, int>
// represent <number, span>

class StockSpanner {
  public:
      // number, span
      stack<pair<int, int>> stk;
      
      StockSpanner() {
      }
      
      int next(int price) {
          int span = 1;
          while(!stk.empty() && stk.top().first <= price) {
              span += stk.top().second;
              stk.pop();
          }
  
          stk.push({price, span});
  
          return span;
      }
  };
  






