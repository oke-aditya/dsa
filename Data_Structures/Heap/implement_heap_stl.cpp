// Implement Heap using Priority Queue

#include <bits/stdc++.h>
using namespace std;

template <typename ... T>

void print_heap(priority_queue<T ...> hp) {

    while(!hp.empty()) {
        cout<<hp.top()<<" ";
        hp.pop();
    }
}

int main(int argc, char const *argv[])
{

    // Creating a max heap using priority queue
    priority_queue<int> maxh;

    // This is directly a max heap and it will be sorted.
    maxh.push(5);
    maxh.push(10);
    maxh.push(2);
    maxh.push(0);

    cout << "Max Heap " << endl;

    // Note that this is printed in reverse order (as seen in stack)
    print_heap(maxh);

    // Creating min heap using priority queue

    priority_queue<int, vector<int>, greater<int>> minh;

    // This is sorted, with greatest element at bottom of stack.
    minh.push(10);
    minh.push(32);
    minh.push(12);
    minh.push(99);

    cout << "Min Heap " << endl;
    print_heap(minh);
    return 0;
}
