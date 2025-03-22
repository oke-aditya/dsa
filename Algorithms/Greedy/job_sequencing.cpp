// Given a set of N jobs where each job i has a deadline and profit associated
// to it. Each job takes 1 unit of time to complete and only one job can be
// scheduled at a time. We earn the profit if and only if the job is completed
// by its deadline. The task is to find the maximum profit and the number of
// jobs done.

// Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to
// that Job.

// Input:
// N = 4
// Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)

// Output:
// 2 60

// Explanation:
// 2 jobs can be done with
// maximum profit of 60 (20+40).

// Input:

// N = 5
// Jobs = (1,2,100)(2,1,19)(3,2,27)
// (4,1,25)(5,1,15)

// Output:
// 2 127

// Explanation:
// 2 jobs can be done with
// maximum profit of 127 (100+27).

// Solution: -
// We can easily solve this using Greedy appraoch.
// First we sort the jobs according to maximum profit possible to earn.
// We would do the job on it's last deadline date possible.
// Then we add the profits whichever jobs can be done.
// We won't be doing some jobs. They are ones with least profits.
// We can fill days before the deadline if it's not possible to do on last day.

#include <bits/stdc++.h>
using namespace std;

// Data structure to store job details. Each job has an identifier,
// a deadline, and profit associated with it.
struct Job {
  int taskID, deadline, profit;
};

bool comparator(Job a, Job b) { return (a.profit > b.profit); }

// Function to schedule jobs to maximize profit
void scheduleJobs(vector<Job> jobs)  // no-ref, no-const
{
  // profit earnt.
  int max_profit = 0;

  // An array to store used and unused info
  vector<int> slot(15, -1);

  // Sort the jobs according to maximum profits to earn.
  sort(jobs.begin(), jobs.end(), comparator);

  // Consider each job which are now sorted in order of profits
  for (auto job : jobs) {
    // Search for next free slot and add it to that slot
    for (int j = job.deadline - 1; j >= 0; j--) {
      if (slot[j] == -1) {
        slot[j] = job.taskID;
        max_profit += job.profit;
        // Allocate just once and break;
        break;
      }
    }
  }

  // Print the scheduled jobs.
  for (int i = 0; i < slot.size(); i++) {
    // We have done it. Print the job id which is in the slot.
    if (slot[i] != -1) {
      cout << slot[i] << " ";
    }
  }
}

int main(int argc, char const *argv[]) {
  vector<Job> jobs = {{1, 9, 15}, {2, 2, 2},  {3, 5, 18}, {4, 7, 1},
                      {5, 4, 25}, {6, 2, 20}, {7, 5, 8},  {8, 7, 10},
                      {9, 4, 12}, {10, 3, 5}};

  // schedule jobs and calculate the maximum profit
  scheduleJobs(jobs);
  cout << endl;
  return 0;
}
