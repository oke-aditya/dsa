// https://leetcode.com/problems/valid-palindrome-ii/description/

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true

// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:

// Input: s = "abc"
// Output: false

#include<string>

using namespace std;

class Solution {
    public:
    
        bool is_palindrome(string s) {
            int left = 0;
            int n = s.size();
            int right = n - 1;
    
            while(left < right) {
    
                // try deleting one?
                if(s[left] != s[right]) {
                    return false;
                }
                left  += 1;
                right -= 1;
            }
            return true;
        }
    
    
        bool validPalindrome(string s) {
            int n = s.size();
            if(n == 0 || n == 1 || n == 2) {
                return true;
            }
    
            if(is_palindrome(s)) {
                // cout<<'y';
                return true;
            }
    
            int left = 0;
            int right = n - 1;
    
            while(left < right) {
    
                // try deleting one?
                if(s[left] != s[right]) {
                    // cout<<left<<" "<<right<<endl; 
                    // cout<<s.substr(left+1, right-left)<<endl;
                    // cout<<s.substr(left, right-left)<<endl;
                    return is_palindrome(s.substr(left+1, right-left)) || is_palindrome(s.substr(left, right-left)); 
                }
                else {
                    left += 1;
                    right -= 1;
                }
            }
    
            return false;
    
        }
    };

