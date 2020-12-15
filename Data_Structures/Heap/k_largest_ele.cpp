// Write an efficient program for printing k
// largest elements in an array.
// Elements in array can be in any order.

// For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are 
// asked for the largest 3 elements i.e., k = 3 
// then your program should print 50, 30 and 23.

#include<bits/stdc++.h>
using namespace std;

vector <int> k_larg_sort(int arr[], int n, int k)
{
    sort(arr, arr + n);
    vector <int> res;
    for(int i=n-1; i>k; i--)
    {
        res.push_back(arr[i]);
    }
    return res;
}

vector <int> k_larg_heap(int arr[], int n, int k)
{
    priority_queue <int, vector<int>, greater<int>> minh;

    for(int i=0; i<n; i++)
    {
        minh.push(arr[i]);
        if(minh.size() > k)
        {
            minh.pop();
        }
    }

    vector <int> res;
    while(!minh.empty())
    {
        res.push_back(minh.top());
        minh.pop();
    }
    return res;

}

void print_vec(vector <int> v)
{
    for(auto x : v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    auto res = k_larg_sort(arr, n, k);
    
    print_vec(res);

    auto res2 = k_larg_heap(arr, n, k);

    print_vec(res2);

    return 0;
}

