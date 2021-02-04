// Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem without modifying the array nums?
// Can you solve the problem using only constant, O(1) extra space?
// Can you solve the problem with runtime complexity less than O(n2)?

// Input: nums = [1,3,4,2,2]
// Output: 2


// Input: nums = [3,1,3,4,2]
// Output: 3

// Solution: -

// 1. Naive approach: -

// Sort the array
// Loop and print. Print number where i == arr[i] and break
// [1 2 2 3 4] . Print element at index i = 2 -> 2 == arr[2];
// Time complexity = O(nlogn)
// Space complexity = O(1) (Can be done in place)

#include<bits/stdc++.h>
using namespace std;

int find_miss_sort(vector <int> v)
{
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
    {
        if(i == v[i])
        {
            return v[i];
        }
    }
    return -1;
}

// 2. Hashmap: -

// Keep count of each of the elements in hashmap
// If count becomes > 1 return the element
// Time complexity = O(n) 
// Space complexity = O(n)


int find_miss_map(vector <int> v)
{
    map <int, int> mp;

    for(int i=0; i<v.size(); i++)
    {
        if(mp[v[i]] == 1)
        {
            return v[i];
        }
        else
        {
            mp[v[i]] += 1;
        }
    }
    return -1;
}

// 3. Linked List style slow and fast pointer.

// Initialize slow pointer and fast pointer to start.
// Move slow pointer by 1 step, fast pointer by 2.
// Finally both will converge at an element say el.
// Return element at index el.

int find_miss_opt(vector <int> v)
{
    int slow = v[0];
    int fast = v[0];

    do
    {
        slow = v[slow];
        fast = v[v[fast]];
    } while (slow != fast);

    fast = v[0];
    while(slow != fast)
    {
        slow = v[slow];
        fast = v[fast];
    }
    return fast;
}


int main(int argc, char const *argv[])
{
    vector <int> v = {1, 3, 4, 2, 2};

    cout<<find_miss_sort(v)<<endl;
    cout<<find_miss_map(v)<<endl;
    cout<<find_miss_opt(v)<<endl;


    return 0;
}


