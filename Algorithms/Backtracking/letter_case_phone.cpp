// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent. 
// Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) 
// is given below. Note that 1 does not map to any letters.

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Input: digits = "2"
// Output: ["a","b","c"]

#include<bits/stdc++.h>
using namespace std;

vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(string digits, int n, vector<string> &res, string &temp)
{
    if(n == digits.length())
    {
        res.push_back(temp);
        return;
    }

    for(auto &c: mapping[digits[n] - '2'])
    {
        temp += c;
        backtrack(digits, n+1, res, temp);
        temp.pop_back();
    }

}


vector<string> letterCombinations(string digits) 
{
    vector<string> res;
    string temp = "";

    if(digits == "")
        return res;

    backtrack(digits, 0, res, temp);

    return res;

}
