// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Notice that the solution set must not contain duplicate quadruplets.

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Input: nums = [], target = 0
// Output: []

#include <bits/stdc++.h>
using namespace std;

// Solution: -
// Brute force solution would be to have 4 loops and find if sum == target.

// Optmized solution is modificatoin of three sum problem.

// Sort the given array.
// For every pivot i, required target = target - v[i]
// The remaining target for every j = target3 - v[j]
// Keep a left pointer to j + 1
// Keep a right pointer to n - 1
// while left < right
// the two sum = v[left] = v[right]
// if it is less, move left by 1
// if it is greater, reduce right.
// if it is equal, add the 4 elements to temp.

// Now skip duplicates.
// while left < right and v[left] == temp[2]
// move left ahead.
// Similar conditiion for right and move right behind.
// Avoid duplicates of i and j similarly.

vector<vector<int>> four_sum(vector<int> v, int target)
{
    vector<vector<int>> res;

    if (v.empty())
    {
        return res;
    }

    int n = v.size();
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int target3 = target - v[i];
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target3 - v[j];
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int two_sum = v[left] + v[right];
                if (two_sum < target2)
                {
                    left += 1;
                }
                else if (two_sum > target2)
                {
                    right -= 1;
                }
                else
                {
                    // This is the perfect sum, add to result
                    vector<int> temp(4, 0);
                    temp[0] = v[i];
                    temp[1] = v[j];
                    temp[2] = v[left];
                    temp[3] = v[right];
                    res.push_back(temp);

                    // Skip all the numbers which are same to left.
                    while (left < right && v[left] == temp[2])
                    {
                        left += 1;
                    }
                    while (left < right && v[right] == temp[3])
                    {
                        right -= 1;
                    }
                }
            }
            // Process duplicates of same number.
            while (j + 1 < n && v[j + 1] == v[j])
            {
                j += 1;
            }
            // Process duplicates of same number.
            while (i + 1 < n && v[i + 1] == v[i])
            {
                i += 1;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto res = four_sum(v, target);

    return 0;
}
