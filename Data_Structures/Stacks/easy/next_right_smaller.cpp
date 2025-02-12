// Given an array of integers, find the closest smaller on right of every element.
// If an element has no smaller on the right side, print -1.

// E.g. array {11, 8, 3, 44};
// Output is [8, 3, -1, -1]

#include<bits/stdc++.h>
using namespace std;

vector<int> nse_naive(int arr[], int n) {
    vector<int> res;
    for(int i=0; i<n; i++) {
        int fg = 1;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[i]) {
                res.push_back(arr[j]);
                fg = 0;
            }
        }
        if(fg) {
            res.push_back(-1);
        }
    }
    return res;
}

void print_v(vector <int> v)
{
    for(auto x : v)
    {
        cout<<x<<" ";
    }
}

vector<int> nse_stack(int arr[], int n)
{

    stack <int> s;
    vector <int> v;

    for(int i=n-1; i>=0; i--)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(!s.empty() && arr[i] > s.top())
        {
            v.push_back(s.top());
        }
        else if(!s.empty() && arr[i] <= s.top())
        {
            while(!s.empty() && arr[i] <= s.top())
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

int main(int argc, char const *argv[])
{
    int arr[] = {11, 8, 3, 44};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto res = nse_naive(arr, n);
    print_v(res);

    auto res = nse_stack(arr, n);

    print_v(res);

    return 0;
}

