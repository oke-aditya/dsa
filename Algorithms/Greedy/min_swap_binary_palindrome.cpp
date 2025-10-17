// Find the minimum number of swaps (any swap allowed, not just adjacent swaps) 
// to make a binary string into a palindrome, if possible.


#include <iostream>
#include <string>
using namespace std;

int minSwapsToMakePalindrome(string s) {
    int n = s.size();
    int count0 = 0, count1 = 0;
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }

    // Check if palindrome is possible
    if ((n % 2 == 0 && (count0 % 2 != 0 || count1 % 2 != 0)) ||
        (n % 2 == 1 && (count0 % 2 + count1 % 2 != 1))) {
        return -1;
    }

    int i = 0, j = n - 1;
    int swaps = 0;

    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } 
        else 
        {
            int k = j;
            while (k > i && s[k] != s[i])  {
                k--;
            }

            if (k == i) 
            {
                // Unique middle character case
                swap(s[i], s[i + 1]);
                swaps++;
            }
            else
            {
                // Bring matching character to the correct position
                while (k < j) {
                    swap(s[k], s[k + 1]);
                    swaps++;
                    k++;
                }
                i++;
                j--;
            }
        }
    }

    return swaps;
}

int main() {
    string s;
    cin >> s;
    cout << minSwapsToMakePalindrome(s) << endl;
    return 0;
}

