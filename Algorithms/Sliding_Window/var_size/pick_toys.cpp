// John is at a toy store help him pick maximum number of toys.
// He can only select in a continuous manner 
// and he can select only two types of toys.

// Example:

// Input:
// 1
// abaccab

// Output:
// 4 -> picks acca

// Solution: -

// Longest substring, with 2 unique characters.
// Length of sliding windows we need to find.
// No. of unique characters = 2.

#include <bits/stdc++.h>
using namespace std;

int pk_toys(string s, int k)
{
    int i = 0, j = 0;
    int max_win_size = -1;
    int n = s.length();

    unordered_map<char, int> mp;

    for (int j = 0; j < n; j++)
    {
        // process every character.
        mp[s[j]] += 1;

        if (mp.size() == k)
        {
            // Maximum window size is max window length.
            max_win_size = max(max_win_size, (j - i + 1));
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                // Cleanup left side.
                mp[s[i]] -= 1;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i += 1;
            }
            // If after cleanup, we satisfy.
            if (mp.size() == k)
            {
                // Maximum window size is max window length.
                max_win_size = max(max_win_size, (j - i + 1));
            }
        }
    }
    return max_win_size;
}

int main(int argc, char const *argv[])
{
    string s = "abaccab";
    int k = 2;

    cout << pk_toys(s, k)<<endl;

    return 0;
}
