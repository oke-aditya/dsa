// https://www.geeksforgeeks.org/next-greater-element/

// Given an array A of size N having distinct elements, the task is to find the next greater element
// for each element of the array in order of their appearance in the array.
// If no such element exists, output -1

// The first line of input contains a single integer T denoting the number of test cases.
// Then T test cases follow.
// Each test case consists of two lines.
// The first line contains an integer N denoting the size of the array.
// The Second line of each test case contains N space separated positive integers denoting the values/elements 
// in the array A

// Input: 1 3 2 4
// Output: 3 4 4 -1

// Input: 4 3 2 1
// Output: -1 -1 -1 -1

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void next_greater_brute(vector <int> v, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(v[j] > v[i])
            {
                cout<<v[j]<<" ";
                break;
            }
        }
        if(j == n)
        {
            cout<<"-1"<<" ";
        }
    }
    cout<<endl;
}

// Push the first element to stack.
// Pick rest of the elements one by one and follow the following steps in loop.
// Mark the current element as next.
// If stack is not empty, compare top element of stack with next.
// If next is greater than the top element,Pop element from stack. next is the next greater element for the popped element.
// Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
// Finally, push the next in the stack.
// After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.

void next_greater_opt(vector <int> v, int n)
{
    vector<int> results(n, 0);
    stack <int> s;
    s.push(v[0]);

    // Iterate over next elements
    for(int i=1; i<n; i++)
    {
        if(s.empty())
        {
            s.push(v[i]);
            continue;
        }
        while(s.empty() == false && s.top() < v[i])
        {
            cout<<v[i]<<" ";
            s.pop();
        }
        s.push(v[i]);
    }
    // If any element is left
    while(!s.empty())
    {
        cout<<"-1"<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    vector <int> v1 = {1, 3, 2, 4};
    int n1 = 4;

    vector <int> v2 = {4, 3, 2, 1};
    int n2 = 4;

    next_greater_brute(v1, n1);
    next_greater_brute(v2, n2);
    
    next_greater_opt(v1, n1);
    next_greater_opt(v2, n2);
    
    return 0;
}


