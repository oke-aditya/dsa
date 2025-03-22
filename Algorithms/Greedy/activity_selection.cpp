// You are given n activities with their start and finish times.
// Select the maximum number of activities that can be performed
// by a single person, assuming that a person can only work on a single activity
// at a time.

// Example 1 : Consider the following 3 activities sorted by
// by finish time.
//      start[]  =  {10, 12, 20};
//      finish[] =  {20, 25, 30};

// A person can perform at most two activities. The
// maximum set of activities that can be executed
// is {0, 2} These are indexes in start[] and  finish[]

// Example 2 : Consider the following 6 activities
// sorted by by finish time.
//      start[]  =  {1, 3, 0, 5, 8, 5};
//      finish[] =  {2, 4, 6, 7, 9, 9};

// A person can perform at most four activities. The
// maximum set of activities that can be executed
// is {0, 1, 3, 4}

// The greedy choice is to always pick the next activity whose finish time
// is least among the remaining activities and the start time is more than or
// equal to the finish time of previously selected activity. We can sort the
// activities according to their finishing time so that we always consider
// the next activity as minimum finishing time activity.

// Solution: -

// 1) Sort the activities according to their finishing time
// 2) Select the first activity from the sorted array and print it.
// 3) Do following for remaining activities in the sorted array.
// a) If the start time of this activity is greater than
// or equal to the finish time of previously selected activity then select this
// activity and print it.

#include <bits/stdc++.h>
using namespace std;

struct Activity {
  int start, finish, pos;
};

bool activity_compare(Activity s1, Activity s2) {
  if (s1.finish < s2.finish) {
    return true;
  } else if (s1.finish > s2.finish) {
    return false;
  } else if (s1.pos < s2.pos) {
    return true;
  } else {
    return false;
  }
}

void print_max_act(int start[], int finish[], int n) {
  struct Activity all_activites[n];
  for (int i = 0; i < n; i++) {
    all_activites[i].start = start[i];
    all_activites[i].finish = finish[i];
    all_activites[i].pos = i + 1;  // + 1 for 1 based indexing.
  }

  // Here we sort by fnish time and whichever has come first.
  sort(all_activites, all_activites + n, activity_compare);

  vector<int> result_finish, result_start;

  // First finishing time.
  int last_finish = all_activites[0].finish;

  // After sorting by finish time, we obviously pick one with least finish time.
  // This is first element.
  result_finish.push_back(all_activites[0].pos);
  result_start.push_back(all_activites[0].start);

  // For all the remaining elements.
  for (int i = 1; i < n; i++) {
    // If the next activity starts after last_finish
    if (all_activites[i].start > last_finish) {
      last_finish = all_activites[i].finish;
      result_start.push_back(all_activites[i].start);
      result_finish.push_back(all_activites[i].finish);
    }
  }

  // Finish time of each of the activities.
  for (int i = 0; i < result_finish.size(); i++) {
    cout << "(" << result_start[i] << " ";
    cout << result_finish[i] << ")";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  // Array containing start time
  int start[] = {5, 1, 3, 0, 5, 8};
  // Array containing finish time
  int finish[] = {9, 2, 4, 6, 7, 9};

  int n = sizeof(start) / sizeof(start[0]);

  print_max_act(start, finish, n);

  return 0;
}
