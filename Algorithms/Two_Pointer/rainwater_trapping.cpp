// Trapping Rain Water
// Given n non-negative integers representing an elevation map where
// the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is
// represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <bits/stdc++.h>
using namespace std;

// Solution: -
// For every element, find maximum to left.
// For every element, find maximum to right.
// trapped water = min(max_left, max_right) - current height.

int trap_brute(vector<int> &height)
{
    int trapped_water = 0, n = height.size();
    for (int i = 0; i < n; i++)
    {
        int left_max = 0, right_max = 0;
        for (int j = i; j > 0; j--)
        {
            left_max = max(left_max, height[j]);
        }
        for (int j = i; j < n; j++)
        {
            right_max = max(right_max, height[j]);
        }
        trapped_water += min(left_max, right_max) - height[i];
    }
    return trapped_water;
}

// Solution: -
// A simple solution would be to keep a suffix array and prefix array.
// In prefix array, keep maximum height of bar from the left end upto
// an index i in the array left_max left max left_max
// In suffix array, keep maximum height of bar from the right end upto
// an index i in the array right_max right max right_max.
// Iterate over the height height height array and update ans:
//     Add min⁡(left_max[i], right_max[i]) to the ans.

int trap_opt(vector<int> &height)
{
    if (height.size() == 0)
    {
        return 0;
    }

    int trapped_water = 0, n = height.size();
    vector<int> left_arr(n);
    vector<int> right_arr(n);

    left_arr[0] = height[0];
    right_arr[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        left_arr[i] = max(height[i], left_arr[i - 1]);
    }

    for (int j = n - 2; j >= 0; j--)
    {
        right_arr[j] = max(height[j], right_arr[j + 1]);
    }

    for (int i = 1; i < n; i++)
    {
        trapped_water += min(left_arr[i], right_arr[i]) - height[i];
    }

    return trapped_water;
}

// Solution: -
// Use two pointers.
//  if there is a larger bar at one end (say right), we are assured
// that the water trapped would be dependant on height of bar in current direction
// (from left to right). As soon as we find the bar at other end (right)
// is smaller, we start iterating in opposite direction (from right to left).

int trap_two_pt(vector<int> &height)
{
    int left = 0, n = height.size(), right = n - 1, trapped_water = 0;
    int left_max = 0, right_max = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= left_max)
            {
                left_max = height[left];
            }
            else
            {
                trapped_water += (left_max - height[left]);
            }
            left += 1;
        }
        else
        {
            if (height[right] >= right_max)
            {
                right_max = height[right];
            }
            else
            {
                trapped_water += (right_max - height[right]);
            }
            right -= 1;
        }
    }
    return trapped_water;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap_brute(v) << endl;
    cout << trap_opt(v) << endl;
    cout << trap_two_pt(v) << endl;

    return 0;
}
