// Includes std::cout (printing) for demo purposes.
#include <iostream>
// Includes the mutex library header.
#include <mutex>
// Includes the thread library header.
#include <thread>

using namespace std;

int count = 0;
mutex m;

// normal mutex
void update() {
  m.lock();
  count += 1;
  m.unlock();
}

void better_update() {
  // The constructor of std::scoped_lock allows for the thread to acquire the
  // mutex m.
  std::scoped_lock slk(m);
  count += 1;

  // Once the function add_count finishes, the object slk is out of scope, and
  // in its destructor, the mutex m is released.
}

int main(int argc, char const *argv[]) {
  thread t1(better_update);
  thread t2(better_update);

  t1.join();
  t2.join();

  cout << "Count = " << count;

  return 0;
}
