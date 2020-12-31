// Given a string you need to print the size of the longest possible
// substring that has exactly k
// unique characters.
// If there is no possible substring print -1.
// Example
// For the string aabacbebebe and
// k = 3 the substring will be
// cbebebe with length 7.

// Example:
// Input:
// 2
// aabacbebebe
// 3
// aaaa
// 1
// Output:
// 7
// 4


#include<bits/stdc++.h>
using namespace std;

int longest_uniq(string s, int k)
{
    int i=0, j=0;
    int max_win_size = -1;
    int n = s.size();

    unordered_map <char, int> mp;

    for(int j=0; j<n; j++)
    {

        // Process each element.
        mp[s[j]]+= 1;

        // If number of unique chars (keys in map).
        if((mp.size()) == k)
        {
            // Store the answer.
            max_win_size = max(max_win_size, (j - i + 1));
        }
        else if((mp.size()) > k)
        {
            // Cleanup left side.
            while((mp.size()) > k)
            {
                // Cleanup left side i.
                // Remove count from map.
                // If it is 0 remove the char.
                mp[s[i]] -= 1;

                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i += 1;
            }
            // If after cleanup we satisfy the condition.
            if((mp.size()) == k)
            {
                // Store the answer.
                max_win_size = max(max_win_size, (j - i + 1));
            }
        }
    }
    return max_win_size;

}

int main(int argc, char const *argv[])
{
    string s = "aabacbebebe";
    int k = 3;
    int res = longest_uniq(s, k);

    string s2 = "aaaa";
    int k2 = 1;
    int res2 = longest_uniq(s2, k2);

    cout<<res<<endl;
    cout<<res2<<endl;


    return 0;
}

