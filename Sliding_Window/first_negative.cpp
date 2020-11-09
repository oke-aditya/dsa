#include<bits/stdc++.h>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k)
{
    queue <int> q1;
    for(int i=0; i<k; i++)
    {
        if(arr[i] < 0)
        {
            q1.push(i);
        }
    }
    if(q1.empty())
    {
        cout<<"0"<<" ";
    }
    // Since we stored the index, we can access it.
    else
    {
        cout<<arr[q1.front()]<<" ";
    }
    
    for(int i=k; i<n; i++)
    {        
        // Cleanup for the leftmost window element
        while( (!q1.empty()) && q1.front() < (i - k + 1))
        {
            q1.pop();
        }

        // Same operation as base problem
        if(arr[i] < 0)
        {
            q1.push(i);
        }

        // If empty we don't have any negative no
        if(q1.empty())
        {
            cout<<"0"<<" ";
        }
        // Since we stored the index, we can access it.
        else
        {
            cout<<arr[q1.front()]<<" ";
        }

    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}
