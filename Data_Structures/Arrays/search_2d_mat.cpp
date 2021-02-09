// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

#include <bits/stdc++.h>
using namespace std;

// 01 03 05 07
// 10 11 16 20
// 23 30 34 60
//

bool search_2d(vector<vector<int>> mat, int tgt)
{
    int m = mat.size();
    int n = mat[0].size();
    bool flag = false;

    int i = 0, j = n - 1;

    while (((i < n - 1) && (j >= 0)))
    {
        if (tgt == mat[i][j])
        {
            flag = true;
            break;
        }
        else if (tgt > mat[i][j])
        {
            i += 1;
        }
        else if (tgt < mat[i][j])
        {
            j -= 1;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    int tgt = 60;

    if (search_2d(mat, tgt))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
