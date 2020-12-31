// Reverse a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void insert_bottom(stack<int> &s, int x)
{
    // If stack is empty push to bottom.
    if (s.size() == 0)
    {
        s.push(x);
    }
    else
    {
        // Get the top element
        int a = s.top();
        s.pop();
        // Insert at bottom again.
        insert_bottom(s, x);
        s.push(a);
    }
}

void reverse_stk(stack<int> &s)
{
    // Base case, if stack is greater than 0
    if (s.size() > 0)
    {
        // Get top element of stack and remove it
        int x = s.top();
        s.pop();

        // Reverse the remaining stack.
        reverse_stk(s);

        // Insert the top elmeent at bottom.
        insert_bottom(s, x);
    }
}

int main(int argc, char const *argv[])
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Stack before reversing: " << endl;
    print_stack(s);
    cout << endl;

    reverse_stk(s);

    cout << "Stack after reversing " << endl;
    print_stack(s);
    cout << endl;

    return 0;
}
