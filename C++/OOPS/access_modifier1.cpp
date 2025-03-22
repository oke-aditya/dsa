// Acces modifiers in C++
// Three types => Public, Private, Protected.
// If we do not specify any access modifiers for the
// members inside the class then by default the access modifier for the members
// will be Private.
//
// Public: -
// The data members and member functions declared
// as public can be accessed by other classes and functions too.
// The public members of a class can be accessed
// from anywhere in the program using the direct member access operator (.) with
// the object of that class.
//
//
// Private: The class members
// declared as private can be accessed only by the
// member functions inside the class. They are
// not allowed to be accessed directly by any
// object or function outside the class. Only the member
// functions or the friend functions are allowed to access the private data
// members of a class.

// Protected access modifier is similar to private access
// modifier in the sense that it can’t be accessed outside
// of it’s class unless with the help of friend class,
// the difference is that the class members declared
// as Protected can be accessed by any subclass(derived class) of that class as
// well.

#include <cmath>
#include <iostream>

class Circle {
 private:
  int circle_id;

 protected:
  std::string circle_details;

 public:
  double radius;

  double compute_area() {
    // M_PI gives pi value.
    double area = this->radius * this->radius * M_PI;
    return area;
  }

  // Simple setter
  void set_circle_details(int circle_id, int radius, std::string circle_det) {
    this->circle_id = circle_id;
    this->circle_details = circle_det;
    this->radius = radius;
  }
};

int main(int argc, char const *argv[]) {
  Circle c1;
  c1.radius = 7.0;

  auto res = c1.compute_area();
  std::cout << res << std::endl;

  // One cannot do
  // c1.circle_id = 5;

  // But one can
  c1.set_circle_details(5, 7.0, "simple one");

  return 0;
}
