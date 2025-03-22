
// Includes the condition variable library header.
#include <condition_variable>
// Includes std::cout (printing) for demo purposes.
#include <iostream>
// Includes the mutex library header.
#include <mutex>
// Includes the thread library header.
#include <thread>

using namespace std;

// Defining a global count variable, a mutex, and a condition variable to
// be used by both threads.
int count = 0;
mutex m;

condition_variable cv;

// In this function, a thread increments the count variable by
// 1. It also will notify one waiting thread if the count value is 2.
// It is ran by two of the threads in the main function.
void add_count_notify() {
  scoped_lock slk(m);
  count += 1;
  if (count == 2) {
    cv.notify_one();
  }
}

void waiter_thread() {
  unique_lock lk(m);
  cv.wait(lk, [] { return count == 2; });

  cout << "Count value = " << count;
}

int main(int argc, char const *argv[]) {
  thread t1(add_count_notify);
  thread t2(add_count_notify);
  thread t3(waiter_thread);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
