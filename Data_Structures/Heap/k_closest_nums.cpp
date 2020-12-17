// Given an unsorted array and
// two numbers x and k,
// find k closest values to x.
// Input : arr[] = {10, 2, 14, 4, 7, 6},
//         x = 5,
//         k = 3

// Output: [4 6 7]

// Solution

// Maintain a max heap with a pair
// pair should contain absolute difference between x and arr[i]
// In other pair variable store only arr[i]
// Since this is heap the first pair variable will be sorted.
// So minimum absolute difference will be sorted.
// As usual insert first k elements
// Pop the top element after every next insert.

#include <bits/stdc++.h>
using namespace std;

vector<int> k_closest_sort(vector<int> v, int k, int tgt)
{

    // Priority queue of of pair, first key is absolute difference, second is arr value.
    priority_queue<pair<int, int>> maxh;

    for (int i = 0; i < v.size(); i++)
    {
        // First push all the elements
        maxh.push({abs(tgt - v[i]), v[i]});

        // If it is greater than k. Start popping them one by one.
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    // Now we have k nearest elements in second item of pair

    vector<int> res;
    while (!maxh.empty())
    {
        res.push_back(maxh.top().second);
        maxh.pop();
    }
    return res;
}

void print_vec(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v{10, 2, 14, 4, 7, 6};
    int k = 3;
    int x = 5;
    auto res = k_closest_sort(v, k, x);

    print_vec(res);

    return 0;
}
