// Intro
// 
// LinkedList is a basic recursive data structure
// We can create this using a simple class or a struct
// 
// Some people start linkedList with a head(0) or sometimes an entire list is given
// To create an empty list, we can create a dummy node that has 0
// Then root->next is actual start of the list
// 0-> node -> node -> node
// node -> node -> node

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // initializer list syntax
    // we can avoid the this-> convention
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};

// we can create a class too 

class ListNode2 {
    public: 

        int val;
        ListNode2* next;

        ListNode2(): val(0), next(nullptr) {}
        ListNode2(int x): val(x), next(nullptr) {}
        ListNode2(int x, ListNode2* next): val(x), next(next) {}
};

// print linked List
void print_ln(ListNode* head) {

    while(head != nullptr) {
        cout<<" "<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int find_length(ListNode *head) {

    int count = 0;
    while(head != nullptr) {
        head = head->next;
        count += 1;
    }

    return count;
}

// fast and slow trick
ListNode* find_mid(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main () {

    // create a pointer, 
    // this already creates a node that has 0 value associate to it
    // we can now create new nodes and link them
    ListNode* node = new ListNode();
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);


    node->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    print_ln(node);
    cout<<find_length(node)<<endl;

    ListNode* mid = find_mid(node);
    cout<<"mid value: "<<mid->val<<endl;


    return 0;
}



