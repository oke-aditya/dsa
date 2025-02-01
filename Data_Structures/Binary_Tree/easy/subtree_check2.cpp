// Given two binary trees with head reference as T and S having at most N nodes.
// The task is to check if S is present as subtree in T.
// A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

// Example 1:

// Input:
// T:      1          S:   3
//       /   \            /
//      2     3          4
//    /  \    /
//   N    N  4
// Output: 1 
// Explanation: S is present in T

//  The idea is based on the fact that inorder
// and preorder/postorder uniquely identify a binary tree. 
// Tree S is a subtree of T if both inorder and preorder traversals
// of S are substrings of inorder and preorder traversals of T respectively.
// 1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
// 2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
// 3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.
// We can also use postorder traversal in place of preorder in the above algorithm.
// 
// 



