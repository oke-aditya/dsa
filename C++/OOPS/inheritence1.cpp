

// Implementing inheritance in C++:
// For creating a sub-class which is inherited from the base class we have to
// follow the below syntax. Syntax: class subclass_name : access_mode
// base_class_name

// Here, subclass_name is the name of the sub class, access_mode is
// the mode in which you want to inherit this sub class for example:
// public, private etc. and base_class_name is the name of the base class from
// which you want to inherit the sub class.

//  A derived class doesn’t inherit access to private data members.
// However, it does inherit a full parent object,
// which contains any private members which that class declares.

// Protected members can be directly accessed.

// Public mode: If we derive a sub class from a
// public base class. Then the public member of the base
// class will become public in the derived class and
// protected members of the base class will become protected in derived class.
//
// Protected mode: If we derive a sub class from a Protected
// base class. Then both public member and protected members
// of the base class will become protected in derived class.
//
// Private mode: If we derive a sub class from a Private base
// class. Then both public member and protected members
// of the base class will become Private in derived class.

#include <bits/stdc++.h>

class SuperClass {
 private:
  int id;

 public:
  std::string details;

 protected:
  int price;
};

class SubClass : public SuperClass {
 private:
  int id;
};

// We can inherit in other models

// class SubClass : private SuperClass

// class SubClass : protected SuperClass

int main(int argc, char const *argv[]) {
  // Create an object of superclass

  SuperClass obj1;

  // We definetely cannot use private and protected members.
  // No access to id and price.

  std::cout << std::endl << obj1.details;

  // Create an object of subclass

  SubClass obj2;

  // We can access the deteails as they are publicly inherited.
  std::cout << std::endl << obj2.details;

  // We cannot access id and price
  // std::cout<<obj2.price<<obj2.id;

  std::cout << std::endl;

  return 0;
}
