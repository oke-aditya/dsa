// Implement Heap using Priority Queue

#include<bits/stdc++.h>
using namespace std;

void print_mx_heap(priority_queue <int> hp)
{
    while(!hp.empty())
    {
        cout<<hp.top()<<" ";
        hp.pop();
    }
    cout<<endl;
}

void print_mn_heap(priority_queue <int, vector<int>, greater<int>> hp)
{
    while(!hp.empty())
    {
        cout<<hp.top()<<" ";
        hp.pop();
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{

    // Creating a max heap using priority queue
    priority_queue <int> maxh;

    // This is directly a max heap and it will be sorted.
    maxh.push(5);
    maxh.push(10);
    maxh.push(2);
    maxh.push(0);

    cout<<"Max Heap "<<endl;

    // Note that this is printed in reverse order (as seen in stack)
    print_mx_heap(maxh);

    // Creating min heap using priority queue

    priority_queue <int, vector<int>, greater<int>> minh;
    
    // This is sorted, with greatest element at bottom of stack.
    minh.push(10);
    minh.push(32);
    minh.push(12);
    minh.push(99);
    
    cout<<"Min Heap "<<endl;
    print_mn_heap(minh);
    return 0;
}

