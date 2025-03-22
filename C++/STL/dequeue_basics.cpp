#include <deque>
#include <iostream>

using namespace std;

void print_dq(deque<int> dq) {
  for (auto x : dq) {
    cout << x << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  deque<int> d1;

  d1.push_back(10);
  d1.push_front(20);
  d1.push_back(30);
  d1.push_front(40);
  d1.push_back(50);

  print_dq(d1);

  cout << "Max size: " << d1.max_size() << endl;
  cout << "Size: " << d1.size() << endl;
  cout << "At no 2" << d1.at(2) << endl;
  cout << "Front element: " << d1.front() << endl;
  cout << "Rear element: " << d1.back() << endl;

  d1.pop_front();
  d1.pop_back();

  print_dq(d1);

  return 0;
}
