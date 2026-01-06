// https://leetcode.com/problems/merge-k-sorted-lists/description/

// You are given an array of k linked-lists lists, 
// each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minh;

        for(auto list: lists) {
            ListNode *curr = list;
            while(curr != nullptr) {
                // cout<<curr->val<<endl;
                minh.push(curr->val);
                curr = curr->next;
            }
        }

        ListNode* new_list = new ListNode();
        ListNode* curr_head = new_list;

        while(!minh.empty()) {
            int val = minh.top();
            ListNode *temp = new ListNode(val);
            curr_head->next = temp;
            curr_head = curr_head->next;
            minh.pop();
        }

        if(new_list->next == nullptr) {
            return nullptr;
        }

        return new_list->next;
    }
};


