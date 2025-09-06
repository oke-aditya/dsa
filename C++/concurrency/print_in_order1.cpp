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
// we can keep a count to notify which thread needs to execute
// based on condition variable we can execute the print statement
// once done we can notify the next

// Instead of relying on a mutex for each of the dependent functions, 
// the dependent functions are blocked by condition variables. 
// This utilizes the passive waitting approach so that the waits on the second and third function 
// relinquish cpu control -- hence conserving resources to be utilized on other active threads.

// Please note that the condition_variables still require a mutex for several reasons

// Protecting access to shared data.

// It is important to note that we still would want synchronization to the 
// writes to the shared memory between the different threads using this object. 
// Relevant to updating first_exec and second_exec.

// Atomicity of wait operations

// The wait operations are reading from shared memory. 

// So, before accessing this shared memory, we want to ensure that the boolean check is on fresh/protected memory. 

// Once the check is performed, the cv wait function is then able to give up the lock until it is 
// signaled to wake up again and re-aqquire the lock. 

// If this action was not atomic, it is possible that the signal to re-perform the check as the
// conditional variable might not be in a waitting state. This is commonly referred to as a lost wakeup.



#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class FooBar {

private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool turn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        
        for (int i = 0; i < n; i++) {

            unique_lock<mutex> ulk(mtx);
            cv.wait(ulk, [this] {return turn;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        
        for (int i = 0; i < n; i++) {
            
            unique_lock<mutex> ulk(mtx);
            cv.wait(ulk, [this]{return !turn; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = true;
            cv.notify_one();
        }

    }
};

