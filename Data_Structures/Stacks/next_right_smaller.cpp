// Given an array of integers, find the closest smaller on right of every element.
// If an element has no smaller on the right side, print -1.

// E.g. array {11, 8, 3, 44};
// Output is [8, 3, -1, -1]

#include<bits/stdc++.h>
using namespace std;

void nse_naive(int arr[], int n)
{
    int next;
    for(int i=0; i<n; i++)
    {
        next = -1;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                next = arr[j];
                break;
            }
        }
        cout<<next<<" ";
    }
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

    nse_naive(arr, n);
    cout<<endl;

    auto res = nse_stack(arr, n);

    print_v(res);

    return 0;
}

