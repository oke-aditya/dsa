// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

// You need to return the number of important reverse pairs in the given array.

// Input: [1,3,2,3,1]
// Output: 2

// Input: [2,4,3,5,1]
// Output: 3

// Solution: -

// Brute Force : -
// Iterate over the arrays using a nested loop.
// Check if v[i] > 2 * v[j] and increase the count
// Return the count.

#include <bits/stdc++.h>
using namespace std;

int reverse_brute(vector<int> v)
{
    int n = v.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > (2 * v[j]))
            {
                count += 1;
            }
        }
    }
    return count;
}

// Optimized Solution: -
// Optimized solution is a modification of merge sort.
// We need to modify the merge step in merge sort.
// In the merge step. Keep two pointers.
// for i = low to i mid
// while j <= mid and v[i] > (2 * v[j])
// increase j to avoid duplicates.
// Increase the cnt as j - (mid + 1) 
// Now follow the usual merge routine.
// check if v[left] <= v[right]
// push to v[left]
// otherwise push to v[right]
// Push remaining left and remaining right
// Finally return count.


int merge(vector<int> &v, int low, int mid, int high)
{
    int cnt = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && v[i] > (2 * v[j]))
        {
            j += 1;
        }
        cnt += (j - (mid + 1));
    }

    vector <int> temp;

    int left = low, right = mid + 1;
    while(left <= mid && right <= high)
    {
        if(v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left += 1;
        }
        else
        {
            temp.push_back(v[right]);
            right += 1;
        }
    }

    while(left <= mid)
    {
        temp.push_back(v[left]);
        left += 1;
    }
    while(right <= high)
    {
        temp.push_back(v[right]);
        right += 1;
    }

    for(int i=low; i<= high; i++)
    {
        v[i] = temp[i - low];
    }
    return cnt;
}

int merge_sort(vector<int> &v, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = (low + high) / 2;
    int inv = merge_sort(v, low, mid);
    inv += merge_sort(v, mid + 1, high);
    inv += merge(v, low, mid, high);
    return inv;
}

int reverse_opt(vector<int> &v)
{
    return merge_sort(v, 0, v.size() - 1);
}

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 3, 2, 3, 1};

    cout << reverse_brute(v1) << endl;

    cout << reverse_opt(v1) << endl;

    vector<int> v2 = {2, 4, 3, 5, 1};

    cout << reverse_brute(v2) << endl;

    cout << reverse_opt(v2) << endl;

    return 0;
}
