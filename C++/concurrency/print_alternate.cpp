// https://leetcode.com/problems/print-foobar-alternately/description/

// The same instance of FooBar will be passed to two different threads:

//     thread A will call foo(), while
//     thread B will call bar().

// Modify the given program to output "foobar" n times.

// Example 1:

// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
// "foobar" is being output 1 time.

// Example 2:

// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.

// Solution

// Again the concept should use condition variable and mutex for binary locks

#include <functional>
#include <mutex>
#include <condition_variable>

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

