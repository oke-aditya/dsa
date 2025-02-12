// https://leetcode.com/problems/validate-stack-sequences/

// Given two sequences pushed and popped with distinct values, return true if
// and only if this could have been the result of a sequence
// of push and pop operations on an initially empty stack.

// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
// Explanation: We might do the following sequence:
// push(1), push(2), push(3), push(4), pop() -> 4,
// push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

// Solution: -
// We push elements from push[i] into the stack,
// and pop them while the top of the stack equals pop[j].
// In the end, if the stack is empty then the sequence is valid.

#include<bits/stdc++.h>
using namespace std;

bool validate_stack_subseq(vector <int> &pushed, vector<int> &popped)
{
    stack <int> stk;
    for(int i=0, j=0; i<pushed.size(); i++)
    {
        stk.push(pushed[i]);
    
        while(!stk.empty() && stk.top() == popped[j])
        {
            stk.pop();
            j += 1;
        }
    }

    return stk.empty();
}


int main(int argc, char const *argv[])
{
    vector <int> pushed = {1, 2, 3, 4, 5};
    vector <int> popped = {4, 5, 3, 2, 1};

    auto res = validate_stack_subseq(pushed, popped);
    
    cout<<res;

    return 0;
}

