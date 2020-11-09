#include<bits/stdc++.h>
using namespace std;

// Algorithm: 

//     Create a queue to store k elements.
//     Run a loop and insert till index less than k(window size) in the queue.
//     Then for index greater than equal to k, check the greater element of current queue and output it. And then 
//     to slide the window, dequeue the first element of queue and enqueue new element of current index in the 
//     queue.
//     And when loop completes, check greater element of queue outside the loop for last window.

int find_max(queue <int> q)
{
    // Maximum value in a queue
    int max = 0;
    while(!q.empty())
    {
        if(q.front() > max)
        {
            max = q.front();
        }
        q.pop();
    }
    return max;
}

void printKMax(int arr[], int n, int k)
{
    queue <int> q;
    // Process first window
    for(int i=0; i<k; i++)
    {
        q.push(arr[i]);
    }
    auto max = find_max(q);
    cout<<max<<" ";
    
    for(int i=k;i<n;i++)
    {
        // Pops the leftmost element
        q.pop();
        // Add rightmost
        q.push(arr[i]);
        auto max = find_max(q);
        cout<<max<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
