
// Given an array, print the Next Greater Element (NGE) to right for every element.
// The Next greater Element for an element x is the first greater element on the right side of x in array.
// Elements for which no greater element exist, consider next greater element as -1.

// Solution: -
//
// Traverse array right to left (opposite)
// If stack is empty
//
// Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element
// for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.
//
// Examples:
//
// For any array, rightmost element always has next greater element as -1.
// For an array which is sorted in decreasing order, all elements have next greater element as -1.
// For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
// [5, 25, 25, -1]

#include <bits/stdc++.h>
using namespace std;

void nge_naive(int arr[], int n)
{
    int next, i, j;
    for (int i = 0; i < n - 1; i++)
    {
        next = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                next = arr[j];
                break;
            }
        }
        cout<<next<<" ";
    }
}

vector<int> nge_stack(int arr[], int n)
{
    stack <int> s;
    vector <int> v;

    for(int i=n-1; i>=0; i--)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(!s.empty() && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if(!s.empty() && s.top() <= arr[i])
        {
            while(!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

void print_v(vector <int> v)
{
    for(auto x : v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // nge_naive(arr, n);
    // cout<<endl;

    auto res = nge_stack(arr, n);
    print_v(res);

    return 0;
}
