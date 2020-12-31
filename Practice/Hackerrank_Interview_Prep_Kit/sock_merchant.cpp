#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sockMerchant(int n, vector<int> &ar) 
{
    int mx = *max_element(ar.begin(), ar.end());
    cout<<mx<<endl;
    int arr[mx+1] = {0};

    for(auto &x : ar)
    {
        arr[x] += 1;
    }
    
    print_arr(arr, mx+1);

    int pairs = 0;
    for(int i=0; i<mx+1; i++)
    {
        pairs = pairs + (int) (arr[i] / 2);
    }
    return pairs;
}

int main(int argc, char const *argv[])
{
    int n = 9;
    vector <int> vec = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    cout<<sockMerchant(n, vec);
    return 0;
}

