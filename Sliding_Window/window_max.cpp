// Given an array arr[] of size N and an integer K.
// Find the maximum for each and every contiguous subarray of size K.

// Example:
// Input 1:
//     A = [1, 3, -1, -3, 5, 3, 6, 7]
//     B = 3
// Output 1:
//     C = [3, 3, 5, 5, 6, 7]

#include <bits/stdc++.h>
using namespace std;

// Algorithm:

//     Create a queue to store k elements.
//     Run a loop and insert till index less than k(window size) in the queue.
//     Then for index greater than equal to k, check the greater element of current queue and output it.
//     To slide the window, dequeue the first element of queue
//     and enqueue new element of current index in the queue.
//     And when loop completes, check greater element of queue outside the loop for last window.

void print_v(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
}

int find_max(queue<int> q)
{
    // Maximum value in a queue
    int max = 0;
    while (!q.empty())
    {
        if (q.front() > max)
        {
            max = q.front();
        }
        q.pop();
    }
    return max;
}

vector<int> print_k_max(int arr[], int n, int k)
{
    vector<int> res;
    queue<int> q;

    // Process first window
    for (int j = 0; j < k; j++)
    {
        q.push(arr[j]);
    }
    auto max = find_max(q);

    res.push_back(max);

    for (int j = k; j < n; j++)
    {
        // Pops the leftmost element Undo step
        q.pop();

        // Add rightmost Process next element
        q.push(arr[j]);

        auto max = find_max(q);
        res.push_back(max);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    auto res = print_k_max(arr, n, k);

    print_v(res);
    return 0;
}
