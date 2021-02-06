// Merge two sorted arrays.

// Time should be O(m + n)

// Easy solution is to use an auxillary array and do merge
// Harder solution is in O(1) time

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> merge_simple(vector<int> v1, vector<int> v2)
{
    // Keep i to track v1
    // Keep j to track v2
    // Track these two till i + j < len(v1) + v2;

    int m = v1.size();
    int n = v2.size();

    vector<int> res;

    int i = 0, j = 0;

    while ((i + j) < (m + n))
    {
        if (i == m)
        {
            res.push_back(v2[j]);
            j += 1;
        }
        else if (j == n)
        {
            res.push_back(v1[i]);
            i += 1;
        }
        else
        {
            if (v1[i] < v2[j])
            {
                res.push_back(v1[i]);
                i += 1;
            }
            else if (v1[i] > v2[j])
            {
                res.push_back(v2[j]);
                j += 1;
            }
            else
            {
                res.push_back(v2[i]);
                i += 1;
                j += 1;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 3, 5, 7};
    vector<int> v2 = {2, 6, 10, 12};

    auto res = merge_simple(v1, v2);

    print_v(res);

    return 0;
}
