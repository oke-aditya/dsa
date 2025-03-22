// https://leetcode.com/problems/assign-cookies/// Given weights and values of N
// items, we need to put these items in a knapsack of capacity W to get the
// maximum total value in the knapsack. Note: Unlike 0/1 knapsack, you are
// allowed to break the item.

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}

// Output:
// 240.00

// Explanation: Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack.

// Input:
// N = 2, W = 50
// values[] = {60,100}
// weight[] = {10,20}

// Output:
// 160.00

// Explanation:
// Total maximum value of item
// we can have is 160.00 from the given
// capacity of sack.

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int value, weight;
};

bool comparator(Item a, Item b) {
  auto a_vw = a.value / a.weight;
  auto b_vw = b.value / b.weight;

  return (a_vw > b_vw);
}

double fractional_knap(vector<Item> v, int W) {
  sort(v.begin(), v.end(), comparator);

  // Total current weight added.
  int curr_w = 0;

  // Finally value of knapsack.
  double final_value = 0;

  // Loop through all items;
  for (int i = 0; i < v.size(); i++) {
    // If we can add the item to knapsack.
    if (curr_w + v[i].weight <= W) {
      curr_w += v[i].weight;
      final_value += v[i].value;
    }

    // We can fill fraction.
    else {
      // This is the remaining weight.
      int remaining = W - curr_w;
      // We need to add only fraction of value.
      final_value += v[i].value * ((double)remaining / (double)v[i].weight);

      // Done the knapsack is filled.
      break;
    }
  }
  return final_value;
}

int main(int argc, char const *argv[]) {
  int W = 50;  //    Weight of knapsack
  // Items <value, weight>
  vector<Item> v = {{60, 10}, {100, 20}, {120, 30}};

  auto res = fractional_knap(v, W);

  cout << res << endl;

  return 0;
}
