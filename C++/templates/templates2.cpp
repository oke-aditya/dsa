// Bubble sort with templates

#include<bits/stdc++.h>
using namespace std;

template <class T>
void bubble_sort(T arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {10, 40, 20, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort<int>(arr, n);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

