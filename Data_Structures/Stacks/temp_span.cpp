// https://leetcode.com/problems/daily-temperatures/

// Given a list of daily temperatures T, return a list such that, for each day in the input,
// tells you how many days you would have to wait until a warmer temperature. If
// there is no future day for which this is possible, put 0 instead.

// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73],
// your output should be [1, 1, 4, 2, 1, 1, 0, 0].

// Note: The length of temperatures will be in the range [1, 30000]. Each
// temperature will be an integer in the range [30, 100]. 

// Stack solution: -
// It is very similar to neareset greater element to right.
// Start from right corner.
// You can keep track of the numbers seen so that when you move left -
//  That left element already knows which is the maximum number it will encounter
// If the current number is smaller than the previously seen number ->
// Simply get the diff in the positions and insert into the stack
// If the number is greater than the previously seen in stack ->
// Keep removing all the numbers (Since we need to find the number larger than it. IF found then great if not then it has result 0).


#include<bits/stdc++.h>
using namespace std;

vector <int> next_temp(vector <int> &temperatures)
{



}


int main(int argc, char const *argv[])
{
    vector <int> temp = {73, 74, 75, 71, 69, 72, 76, 73};

    auto res = next_temp(temp);

    return 0;
}



