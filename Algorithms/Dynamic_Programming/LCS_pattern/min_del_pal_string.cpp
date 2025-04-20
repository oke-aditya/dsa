#include <bits/stdc++.h>
using namespace std;

// Given a string of size ‘n’.
// The task is to remove or delete the minimum number of characters from the
// string so that the resultant string is a palindrome.

// Input : aebcbda
// Output : 2
// Remove characters 'e' and 'd'
// Resultant string will be 'abcba'
// which is a palindromic string

// Input : geeksforgeeks
// Output : 8

// Solution: -
// Find length of longest palindormic subsequence.
// The remaining characters have to be deleted to make the resultant string to a
// palindrome. minimum number of deletions = n - len of longest palindromic
// substring.
// Same as minimum number of insertions needed

