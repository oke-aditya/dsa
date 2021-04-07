// Given a balanced parentheses string S, compute the score of the string based on the following rule:

// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.

// Input: "()"
// Output: 1

// Input: "(())"
// Output: 2

// Input: "()()"
// Output: 2

// Input: "(()(()))"
// Output: 6

// S is a balanced parentheses string, containing only ( and ).
// 2 <= S.length <= 50


// Solution:
// When travel through S, only meets ')', we need to calculate the score of
// this pair of parenthese. If we know the score of inner parentheses, such
// as 3, we can double it and pass to the outer parenthese. But the question
// is how do we know the score of inner parentheses? Using stack.
// explain with "( ( ) ( ( ) ) )"

// stack: 0->
// string_traveled :""
// When start only 0 in stack, this int will store the total score

// stack: 0->0->0->
// string_traveled:"( ("
// Meet two '(', push two zeros to the stack

// stack: 0->1->
// string_traveled: "( ( )"
// First time meets ')', it balance the last '(', so pop the stack. But 0 indicates no inner parentheses exists, so just pass 1 to parent parenthese.

// stack: 0->1->0->0->
// string_traveled: "( ( ) ( ("
// Keep pushing zeros

// stack 0->1->1->
// string_traveled: "( ( ) ( ( )"
// Balance one '(', and still no inner parenthese, so pass 1 to parent

// stack 0->3->
// string_traveled: "( ( ) ( ( ) )"
// Balance another '(', but the inner is not zero, so double it and add to parent's score

// stack 6->
// string_traveled: "( ( ) ( ( ) ) )"
// Same as last step, double the inner score and add to parent's

#include<bits/stdc++.h>
using namespace std;

int score_par(string s)
{
    // Stack stores scores of prans
    stack <int> stk;

    // To keep the total score.
    stk.push(0);

    for(char c: s)
    {
        if(c == '(')
        {
            // Opening brace does not contribute to score
            stk.push(0);
        }
        // Closing brace
        else
        {
            // Current score
            int tmp = stk.top();

            stk.pop();

            int val = 0;
            if(tmp > 0) // This means paranthesis exists.
            {
                val = tmp * 2;
            }

            else  /// tmp value is 0, we got first matching brace.
            {
                val += 1;
            }

            // Add the score to top
            stk.top() += val;
        }
    }

    // Final score left.
    return stk.top();

}



int main(int argc, char const *argv[])
{

    string s1 = "()";
    string s2 = "(())";
    string s3 = "()()";
    string s4 = "(()(()))";

    auto res1 = score_par(s1);
    auto res2 = score_par(s2);
    auto res3 = score_par(s3);
    auto res4 = score_par(s4);

    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
    cout<<res4<<endl;
    
    return 0;
}

