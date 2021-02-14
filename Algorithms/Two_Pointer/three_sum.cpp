// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Input: nums = [0]
// Output: []

#include <bits/stdc++.h>
using namespace std;

// Solution: -
// Brute force approach is to iterate with three loops.
// Check if sum of all three is 0
// If true simple add to result temp and retunr result.
// To take care of duplicates, we would need to make set and store values in a set.

vector<vector<int>> three_sum_brute(vector<int> v)
{
    int n = v.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((v[i] + v[j] + v[k]) == 0)
                {
                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[j]);
                    temp.push_back(v[k]);
                    res.push_back(temp);
                }
            }
        }
    }
    return res;
}

// Optimized Solution: -
// Sort the array.
// Assume that one element is a pivot.
// if i == 0 or i > 0 && v[i] != v[i-1]. To avoid duplicates.
// for this element find sum that is = 0 - element.
// Keep a left pointer = i + 1, right pointer = n - 1
// if v[left] + v[right] == sum
// push values to temp result.
// to avoid duplicate processing.
// if v[left] == v[left + 1] and left < rigiht
// keep moving left += 1
// Simlar condition for right and move right behind.
// if both are less than sum
// move left ahead.
// if both are greater than sum
// move right behding.

vector<vector<int>> three_sum_opt(vector<int> v)
{
    int n = v.size();
    vector<vector<int>> res;
    sort(v.begin(), v.end());

    // moves for a
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && v[i] != v[i - 1]))
        {
            int left = i + 1, right = n - 1, sum = 0 - v[i];
            while (left < right)
            {
                if (v[left] + v[right] == sum)
                {
                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[left]);
                    temp.push_back(v[right]);
                    res.push_back(temp);

                    while (left < right && v[left] == v[left + 1])
                    {
                        left += 1;
                    }
                    while (left < right && v[right] == v[right - 1])
                    {
                        right -= 1;
                    }
                    left += 1;
                    right -= 1;
                }
                else if (v[left] + v[right] < sum)
                {
                    left += 1;
                }
                else
                {
                    right -= 1;
                }
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto res = three_sum_brute(v);
    auto res2 = three_sum_opt(v);

    return 0;
}
