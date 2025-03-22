#include <iostream>
// Includes the mutex library header.
#include <mutex>
// Includes the thread library header.
#include <thread>

using namespace std;

int count = 0;

mutex m;

void add_count() {
  m.lock();
  count += 1;
  m.unlock();
}

int main(int argc, char const *argv[]) {
  thread t1(add_count);
  thread t2(add_count);

  t1.join();
  t2.join();

  cout << "Current count = " << count << endl;

  return 0;
}
