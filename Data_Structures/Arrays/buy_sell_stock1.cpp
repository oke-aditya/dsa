// Best Time to Buy and Sell Stock

#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Solution: -
// Brute force approach: - Calculate all the possible differnece form j = i + 1 to n
// Optimal approach: -
// Keep a track of minimal price as well as maximal price
// Find the max profit between them.


int buy_sell_brute(vector<int> v)
{
    int n = v.size();
    int max_p = 0, temp;

    for(int i=0; i<v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            temp = v[j] - v[i];
            max_p = max(max_p, temp);
        }
    }
    return max_p;
}

int buy_sell_opt(vector <int> v)
{
    int n = v.size();
    int max_p = 0, min_price = INT_MAX;
    
    for(int i=0; i<n; i++)
    {
        min_price = min(v[i], min_price);
        max_p = max(v[i] - min_price, max_p);
    }
    
    return max_p;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout<<buy_sell_brute(v)<<endl;
    cout<<buy_sell_opt(v)<<endl;



    return 0;
}
