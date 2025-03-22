#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5};

  vector<int>::iterator itr1;

  cout << "Vector eleements printed using iterator are " << endl;

  for (itr1 = arr.begin(); itr1 != arr.end(); itr1++) {
    cout << *itr1 << " ";
  }
  cout << endl;

  auto itr2 = arr.begin();
  advance(itr2, 3);

  cout << "Position after advancing the vector = " << *itr2 << endl;

  auto itr3 = next(itr2);

  cout << "Position next to first iterator = " << *itr3 << endl;

  auto itr4 = prev(itr3);

  cout << "Position prev to first iterator = " << *itr4 << endl;

  return 0;
}
