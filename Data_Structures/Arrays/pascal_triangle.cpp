// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

// Solution: -
// Create Result vector<vector> of size number of rows.
// For every row -> i
// For each i resize the the internal vector to size i + 1.
// since first and last element are 1, res[i][0] = 1 and result[i][i] = 1;
// Every row of pascal triangle can be filled as
// res[i][j] = res[i-1][j-1] + res[i-1][j];

#include <bits/stdc++.h>
using namespace std;

void print_vv(vector<vector<int>> vv)
{
    for (auto v : vv)
    {
        cout << "[";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "]";
        cout << endl;
    }
}

vector<vector<int>> generate_pascal(int n_rows)
{
    vector<vector<int>> res(n_rows);

    for (int i = 0; i < n_rows; i++)
    {
        res[i].resize(i + 1);

        // First element is 1.
        res[i][0] = 1;
        // Last element is 1.
        res[i][i] = 1;

        // Fill every row of pascal triangle
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    auto res = generate_pascal(n);
    print_vv(res);
    return 0;
}
