#include <bits/stdc++.h>
using namespace std;

int g_count = 0;
shared_mutex sm;

void read_value() {
  shared_lock sl(sm);
  cout << "count = " << to_string(g_count);
}

void write_value() {
  unique_lock ul(sm);
  g_count += 3;
}

int main(int argc, char const *argv[]) {
  thread t1(read_value);
  thread t2(write_value);
  thread t3(read_value);
  thread t4(read_value);
  thread t5(write_value);
  thread t6(read_value);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();

  return 0;
}
