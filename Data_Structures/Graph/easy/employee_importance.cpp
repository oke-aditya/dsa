// https://leetcode.com/problems/employee-importance/description/
// You have a data structure of employee information, including the employee's unique ID, 
// importance value, and direct subordinates' IDs.

// You are given an array of employees employees where:
// employees[i].id is the ID of the ith employee.
// employees[i].importance is the importance value of the ith employee.
// employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.

// Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
// Output: 11
// Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
// They both have an importance value of 3.
// Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.

#include <bits/stdc++.h>
using namespace std;

// Definition for Employee.
class Employee {
    public:
        int id;
        int importance;
        vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int, Employee*> mp;
        for(auto emp: employees) {
            mp[emp->id] = emp;
        }

        int total_importance = 0;

        // we need to do a BFS from given id to the other nodes?
        queue<Employee *> q;
        q.push(mp[id]);

        while(!q.empty()) {
            Employee* emp = q.front();
            q.pop();
            total_importance += emp->importance;

            for(auto sub: emp->subordinates) {
                q.push(mp[sub]);
            }
        }

        return total_importance;

    }
};