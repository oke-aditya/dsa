// C++ libraries provide implementations of smart pointers in following types:

// auto_ptr (Deperecated in C++ 11)
// unique_ptr
// shared_ptr
// weak_ptr

// auto_ptr is a smart pointer that manages an object obtained
// via new expression and deletes that object when auto_ptr itself is destroyed.
// It takes ownership of the pointer in a
// way that no two pointers should contain the same object. Assignment transfers
// ownership and resets the rvalue auto pointer to a null pointer. Thus, they
// can’t be used within STL containers due to the aforementioned inability to be
// copied.

// Unique ptr
// std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.
// unique_ptr is a new facility with similar functionality,
// but with improved security (no fake copy assignments),
// added features (deleters) and support for arrays. It is a container for raw
// pointers. It explicitly prevents copying of its contained pointer as would
// happen with normal assignment i.e. it allows exactly one owner of the
// underlying pointer. there can only be at most one unique_ptr at any one
// resource and when that unique_ptr is destroyed, the resource is automatically
// claimed

// since there can only be one unique_ptr to any resource,
// so any attempt to make a copy of unique_ptr will cause a compile-time error

// unique_ptr can be moved using the new move semantics i.e.
// using std::move() function to transfer ownership of the contained pointer to
// another unique_ptr. So, it’s best to use unique_ptr when we want a single
// pointer to an object that will be reclaimed when that single pointer is
// destroyed.

#include <bits/stdc++.h>
using namespace std;

class Simple {
 public:
  void show() { cout << "Show method called" << endl; }
};

int main(int argc, char const *argv[]) {
  unique_ptr<Simple> p1(new Simple);

  p1->show();

  // Return memory addres of p1.
  cout << p1.get() << endl;

  // Transfer ownership to p2.
  unique_ptr<Simple> p2 = move(p1);

  p2->show();

  // Print mem address.
  cout << p1.get() << endl;  // NULL
  cout << p2.get() << endl;

  // Transfer ownership to p3
  unique_ptr<Simple> p3 = move(p2);
  p3->show();

  cout << p1.get() << endl;  // NULL
  cout << p2.get() << endl;  // NULL
  cout << p3.get() << endl;

  return 0;
}
