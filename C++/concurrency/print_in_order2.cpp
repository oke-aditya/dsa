// https://leetcode.com/problems/print-in-order/description/

// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }

// The same instance of Foo will be passed to three different threads. 
// Thread A will call first(), thread B will call second(), and thread C will call third().
// Design a mechanism and modify the program to ensure that second()
// is executed after first(), and third() is executed after second().

// Note:

// We do not know how the threads will be scheduled in the operating system, 
// even though the numbers in the input seem to imply the ordering. 
// The input format you see is mainly to ensure our tests' comprehensiveness.

// Example 1:

// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. 
// The input [1,2,3] means thread A calls first(), thread B calls second(), 
// and thread C calls third(). "firstsecondthird" is the correct output.

// Example 2:

// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), 
// and thread C calls second(). "firstsecondthird" is the correct output.

// Solution: -
// The idea here is to implement concurrency control on threads
// Note that this is threading, so we can use our concepts such as mutex and condition variable

// This approach uses a mutex for each of the two dependent function calls. 
// At the beginning, all the locks are claimed in the constructor. 
// This ensures that none of the funcitons of requiring a lock are able to grasp or get ownership of the mutex. 
// When they attempt to (with their .lock() call, their thread is blocked until that mutex is released. 
// The only way a mutex can be released is with a call to .unlock, which is called at the end of first. 
// So when first finishes executing, then the lock can finally be aquired by second (with the call to .lock). 
// This function then releases the third lock so that the third_lock mutex can be aquired by third, 
// and the flow can finish. 
// The downside to this approach is that second and third functions are using busy-waitting/active-waitting/spinning 
// for unlocking, meaning that the threads will continue to consume CPU resources actively while waitting. 
// For more detail, this poor waitting mechanism requires the thread to repeatedly check a condition in a loop waitting 
// for some event to occur -- which doesn't relinquish control of the cpu.
// The advantage of active waitting is that it leads to very fast response times for the thread to 
// re-initiate (as it doesn't have to endure the overhead of being put to sleep and then woken up again).


// this is also an abuse of mutex. 
// as ideally same function should unlock the mutex that it has created

#include <mutex>
#include <functional>

using namespace std;

class Foo {
    mutex m1, m2, m3;

public:
    Foo() {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst) {

        m1.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3.unlock();
        
    }

    void third(function<void()> printThird) {
        
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m1.unlock();
    }
};
