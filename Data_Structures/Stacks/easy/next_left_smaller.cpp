// Given an array of integers, find the closest 
// smaller on left of every element. 
// If an element has no smaller on the left side, print -1.
// Example
// int arr[] = {4, 5, 2, 10, 8}
// Output = [-1, 4, -1, 2, 2]

#include<bits/stdc++.h>
using namespace std;

void naive_nse(int arr[], int n)
{
    int next;
    for(int i=0; i<n; i++)
    {
        next = -1;
        for(int j=i-1; j>=0; j--)
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

vector <int> nse_stack(int arr[], int n)
{
    vector <int> v;
    stack <int> s;

    for(int i=0; i<n; i++)
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
    int arr[] = {4, 5, 2, 10, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    naive_nse(arr, n);
    cout<<endl;

    auto res = nse_stack(arr, n);
    print_v(res);

    return 0;
}

