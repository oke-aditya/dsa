// Given a balanced expression that can contain opening and closing parenthesis,
// check if the expression contains any duplicate parenthesis or not.

// Input: ((x+y))+z
// Output: Duplicate Paranthesis found
//

// Input: (x+y)
// Output: No Duplicate () found
//

// ((x+y)+((z)))
// Output: Duplicate () found
//

#include <iostream>
#include <stack>

using namespace std;

string dup_paran(string s) {
  if (s.length() <= 3) {
    return ("No duplicate paranthesis");
  }

  stack<char> stk;

  // Traverse the string
  for (char chr : s) {
    // Not a closing paran. Push to stack
    if (chr != ')') {
      stk.push(chr);
    }

    // Closing paran
    else {
      if (stk.top() == '(') {
        // If top is opening '('.
        return "Duplicate paranthesis found";
      } else {
        // Pop till '(' is not found.
        while (stk.top() != '(') {
          stk.pop();
        }
        // We found '('
        stk.pop();
      }
    }
  }

  // If we reach here paranthesis are balanced
  return "No duplicate paranthesis found";
}

int main(int argc, char const *argv[]) {
  string s1 = "((x+y))+z";
  string s2 = "(x+y)";
  string s3 = "((x+y))+(((z)))";

  auto res1 = dup_paran(s1);
  auto res2 = dup_paran(s2);
  auto res3 = dup_paran(s3);

  cout << res1 << endl;
  cout << res2 << endl;
  cout << res3 << endl;

  return 0;
}
