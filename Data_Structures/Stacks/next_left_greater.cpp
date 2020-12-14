// Given an array of integers, find the closest
// greater on left of every element. 
// If an element has no greater on the left side, print -1.
// E.g. array {11, 13, 21, 3};
// Output will be {-1, -1, -1, 21}


#include<bits/stdc++.h>
using namespace std;

void nge_naive(int arr[], int n)
{
    int next;

    for(int i=0; i<n; i++)
    {
        next = -1;
        for(int j=i-1; j>=0; j--)
        {
            if(arr[j] > arr[i])
            {
                next = arr[j];
                break;
            }
        }
        cout<<next<<" ";
    }
}

vector <int> nge_stack(int arr[], int n)
{
    stack <int> s;
    vector <int> v;

    for(int i=0; i<n; i++)
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
                v.push_back(arr[i]);
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
}


int main(int argc, char const *argv[])
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    nge_naive(arr, n);
    cout<<endl;

    auto res = nge_stack(arr, n);
    print_v(res);

    return 0;
}

