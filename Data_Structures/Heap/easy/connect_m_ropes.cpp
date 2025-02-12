// https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/

// There are given n ropes of different lengths, we need to connect these ropes into one rope.
// The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

// For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
// 1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
// 2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
// 3) Finally connect the two ropes and all ropes have connected.

// Total cost for connecting all ropes is 5 + 9 + 15 = 29.
// This is the optimized cost for connecting ropes. Other ways of
// connecting ropes would always have same or more cost. For example,
// if we connect 4 and 6 first (we get three strings of 3, 2 and 10),
// then connect 10 and 3 (we get two strings of 13 and 2).
// Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

// Solution
// Create min heap, push all elements to it
// while size of min heap is less than 2 pop 2 elements from the top and add to result
// Push back result to min heap.
// Finally add final element of min heap to result and return result.

#include <bits/stdc++.h>
using namespace std;

int connect_ropes(vector<int> v)
{
    int n = v.size();

    int cost = 0;

    priority_queue<int, vector<int>, greater<int>> minh;

    for(auto x : v)
    {
        minh.push(x);
    }

    while (minh.size() >= 2)
    {
        int first = minh.top();
        minh.pop();
        int second = minh.top();
        minh.pop();

        cost = cost + first + second;;
        minh.push((first + second));
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    vector<int> v{4, 3, 2, 6};

    auto res = connect_ropes(v);

    cout << res << endl;

    return 0;
}
