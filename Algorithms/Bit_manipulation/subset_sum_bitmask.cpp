#include <iostream>
using namespace std;
int main() {
  int n, arr[15], p, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cin >> p;  // Number to who the subset sum will be equated

    bool flag = false;
    // Generate all the possible subarrays

    int total = 1 << n;
    for (int mask = 0; mask < total; mask++) {
      int sum = 0;
      for (int i = 0; i < n; i++)  // Checks if ith element exists or not
      {
        int f = 1 << i;  // To check if ith bit is 1.
        if ((mask & f) != 0) {
          // ith elemenet exists
          // Add the ith element in the sum
          sum += arr[i];
        }
      }
      if (sum == p) {
        // There is single subarray that is true
        flag = true;
        break;
      }
    }
    if (flag == true) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
