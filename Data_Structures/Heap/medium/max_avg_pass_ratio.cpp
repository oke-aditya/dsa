// https://leetcode.com/problems/maximum-average-pass-ratio/

// There is a school that has classes of students and each class will be having a final exam. 
// You are given a 2D integer array classes, where classes[i] = [passi, totali]. 
// You know beforehand that in the ith class, there are totali total students, 
// but only passi number of students will pass the exam.

// You are also given an integer extraStudents. 
// There are another extraStudents brilliant students that are guaranteed 
// to pass the exam of any class they are assigned to. 
// You want to assign each of the extraStudents students to a class in a 
// way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class 
// that will pass the exam divided by the total number of students of the class. 
// The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents students. 
// Answers within 10-5 of the actual answer will be accepted.


// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485

// solution:

// brute force
// see how the ratio changes and allocate the student
// allocate student where the max ratio changes
// compute the total pass ratio

#include <queue>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class Solution2 {
public:
    double maxAverageRatioBrute(vector<vector<int>>& classes, int extraStudents) {
        double end_pass_rate = 0, n = classes.size();
        // classes[0][0] += 2;
        // classes[0][1] += 2;

        while(extraStudents--) {
            double max_delta = 0.0;
            int allocation_index = 0;
            for(int i=0; i<n; i++) {
                // find the delta between current pass ratio and if student was allocated
                double current_pass_rate = ((double) classes[i][0] / classes[i][1]);
                double future_pass_rate = ((double) (classes[i][0] +1) / (classes[i][1] + 1));

                double new_delta = future_pass_rate - current_pass_rate;

                // cout<<"i:"<<i<<"new_delta: "<<new_delta<<endl;

                // if the delta is largest allocate student there
                if(new_delta > max_delta) {
                    allocation_index = i;
                    max_delta = new_delta;
                }
            }

            // cout<<"ai: "<<allocation_index<<endl;
            classes[allocation_index][0] += 1;
            classes[allocation_index][1] += 1;
        }

        for(auto class_: classes) {
            end_pass_rate +=  ((double) class_[0] / class_[1]);
            cout<<end_pass_rate<<endl;
        }

        return (end_pass_rate / n);
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double end_pass_rate = 0, n = classes.size();
        // classes[0][0] += 2;
        // classes[0][1] += 2;

        // first would be future delta, and then the pair
        priority_queue<pair<double, pair<int, int>>> maxh;
        
        // compute the initial delta
        for(int i=0; i<n; i++) {
            double current_pass_rate = ((double) classes[i][0] / classes[i][1]);
            double future_pass_rate = ((double) (classes[i][0] +1) / (classes[i][1] + 1));
            double new_delta = future_pass_rate - current_pass_rate;
            // maxh.push({make_pair(future_pass_rate, make_pair(classes[i][0], classes[i][1]))})
            maxh.push({new_delta, {classes[i][0], classes[i][1]}});
        }

        while(extraStudents--) {
            double max_delta = 0.0;
            // int allocation_index = 0;
            pair<double, pair<int, int>> delta_pair = maxh.top();
            maxh.pop();

            // we need to recompute, as student is allocated here
            // current pass rate is after allocating the student
            double current_pass_rate = ((double) (delta_pair.second.first + 1) / (delta_pair.second.second + 1));

            // new pass rate is what would happen if we give yet another student
            double new_pass_rate = ((double) (delta_pair.second.first + 2) / (delta_pair.second.second + 2));
            
            double new_delta = new_pass_rate - current_pass_rate;
            
            maxh.push({new_delta, {delta_pair.second.first + 1, delta_pair.second.second + 1}});
        }

        // pop the max heap and compute the delta that is currently not future.
        while(!maxh.empty()) {
            // cout<<maxh.top().second.first<<"/"<<maxh.top().second.second<<endl;
            // cout<<maxh.top().second<endl;
            end_pass_rate +=  ((double) maxh.top().second.first / maxh.top().second.second);
            maxh.pop();
            // cout<<end_pass_rate<<endl;
        }

        return (end_pass_rate / n);
    }
};
