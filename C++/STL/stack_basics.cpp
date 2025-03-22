#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<int> s1) {
  while (!s1.empty()) {
    cout << s1.top() << " ";
    s1.pop();
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(3);
  s1.push(1);

  print_stack(s1);

  cout << "Size of the stack " << s1.size() << endl;
  cout << "Top of the stack " << s1.top() << endl;

  return 0;
}
