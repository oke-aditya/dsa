// Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

// Follow up:

//     A straight forward solution using O(mn) space is probably a bad idea.
//     A simple improvement uses O(m + n) space, but still not the best solution.
//     Could you devise a constant space solution?

// Solution: -

// Keep track of zeros and ones using m elements for row and n for columns
// Set them to -1
// Iterate through every elmeent of matrix.
// If it is 0, set the row[i] to 0 and col[j] to 0.

// Now Iterate through row and col
// If row[i] == 0 || col[j] == 0
// Set mat[i][j] to 0.

#include <bits/stdc++.h>
using namespace std;

// void print_vv(vector<vector<int>> vv)
// {
//     for(auto v: vv)
//     {
//         cout<<"[";
//         for(int i=0; i<v.size(); i++)
//         {
//             cout<<" "<<v[i];
//         }
//         cout<<"]";
//     }
//     cout<<endl;
// }

void print_mat(vector<vector<int>> mat)
{
    for (auto row : mat)
    {
        for (int i = 0; i < row.size(); i++)
        {
            cout << row[i] << " ";
        }
        cout << endl;
    }
}

void set_zeros(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    // cout<<m<<" "<<n;

    int row[m], col[n];
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((row[i] == 0 || col[j] == 0) )
            {
                mat[i][j] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    print_mat(v);
    set_zeros(v);

    cout << endl;
    print_mat(v);

    return 0;
}
