// Given an array containing N positive integers
// and an integer K.
// Your task is to find the length of the longest Sub-Array with
// sum of the elements equal to the given value K.

// For Input:
// 1
// 7 5
// 4 1 1 1 2 3 5
// Output:
// 4

#include <bits/stdc++.h>
using namespace std;

// This does not work for negative numbers.
// Also we cannot find the count.
// For finding the count, we should use the prefix sum logic.
// 
// Sliding window logic doesn't work as we accumulate the result 
// and then invalidate.

// Consider case [-1, -1, 1]. And target sum = 0;
// Since we accumulate the sum, we cannot find the window [-1, 1].
// That's why logic will not work for -ve numbers and -ve K.



int max_sum_k(vector<int> v, int k)
{
    int i = 0, j = 0; // initial pointer locations
    int n = v.size();
    int max_win_size = -1;
    int win_sum = 0;

    for (j = 0; j < n; j++)
    {
        // Add each element to window sum.
        win_sum += v[j];
        if (win_sum == k)
        {
            // We need to store answers.
            // Window size is (j - i  + 1)
            max_win_size = max(max_win_size, (j - i + 1));
        }
        else if (win_sum > k)
        {
            // Cleanup left side.
            while (win_sum > k)
            {
                // Cleanup i elements.
                win_sum = win_sum - v[i];
                i += 1;
            }
            // If after cleaning we reach the sum. See testcase 3.
            if (win_sum == k)
            {
                // We need to store answers.
                // Window size is (j - i  + 1)
                // if the window is not empty.
                if(j - i + 1 != 0) {
                    max_win_size = max(max_win_size, (j - i + 1));
                }
            }
        }
    }
    return max_win_size;
}

int main(int argc, char const *argv[])
{
    vector<int> v{4, 1, 1, 1, 2, 3, 5};
    int k = 5;

    vector <int> v2 { 10, 5, 2, 7, 1, 9 };
    int k2 = 15;

    vector<int> v3{4, 1, 1, 1, 2, 3, 5};
    int k3 = 4;

    cout << max_sum_k(v, k) << endl;
    cout << max_sum_k(v2, k2) << endl;
    cout << max_sum_k(v3, k3) << endl;

    return 0;
}
