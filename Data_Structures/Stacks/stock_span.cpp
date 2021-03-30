// The stock span problem is a financial problem
// where we have a series of n daily price quotes
// for a stock and we need to calculate the span of stock’s price for all n days.
// The span Si of the stock’s price on a given day
// i is defined as the maximum number of consecutive
// days just before the given day, for which
// the price of the stock on the current day is greater than its price on the previous days.
// For example, if an array of 7 days prices is given
// as {100, 80, 60, 70, 60, 75, 85}, then
// the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
// https://www.geeksforgeeks.org/the-stock-span-problem/

// Solution: -
// Brute force
// Iterate twice over the array.
// Find days when stock was greater, add result to array.

#include<bits/stdc++.h>
using namespace std;

void print_v(vector <int> v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

vector <int> stock_span_brute(vector <int> v)
{
    vector <int> span;
    int n = v.size();
    // Span of first day is always 1.
    span.push_back(1);

    for(int i=1; i<n; i++)
    {
        int span_count = 1;
        // cout<<span_count<<endl;

        cout<<v[i]<<endl;

        for(int j=i-1; j>=0; j--)
        {
            if(v[i] >= v[j])
            {
                span_count += 1;
            }
            else
            {
                // The span other stock is greater, so break;
                break;
            }
            
        }
        // cout<<span_count<<endl;
        span.push_back(span_count);
    }
    return span;
}

// Optimal solution.
// We just need to find the nearest element greater to left.
// Keep a counter to track it as well.

vector <int> stock_span_stack(vector<int> v)
{
    // Use stack as temp buffer to store indices.
    stack <int> st;
    // First index
    st.push(0);

    vector <int> span;
    // Span of first is always 1.
    span.push_back(1);

    // For next elements.
    for(int i=1; i<v.size(); i++)
    {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while(!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }

        // Either stack will be empty
        if(st.empty())
        {
            // Then current index is span.
            span.push_back(i + 1);
        }
        // v[st.top() > v[i]]
        else
        {
            // Span is indices traversed till here.
            span.push_back(i - st.top());
        }
        // Add this index to process.
        st.push(i);
    }
    return span;
}

int main(int argc, char const *argv[])
{
    vector <int> v = {10, 4, 5, 90, 120, 80 };

    auto res = stock_span_brute(v);
    print_v(res);

    auto res2 = stock_span_stack(v);
    print_v(res2);

    return 0;
}

