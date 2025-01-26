// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Given number of pages in n different books and m students.
// The books are arranged in ascending order of number of pages.
// Every student is assigned to read some consecutive books.
// The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
// Input : pages[] = {12, 34, 67, 90}
//         m = 2
// Output : 113
// Explanation:
// There are 2 number of students. Books can be distributed
// in following fashion :
//   1) [12] and [34, 67, 90]
//       Max number of pages is allocated to student
//       2 with 34 + 67 + 90 = 191 pages
//   2) [12, 34] and [67, 90]
//       Max number of pages is allocated to student
//       2 with 67 + 90 = 157 pages
//   3) [12, 34, 67] and [90]
//       Max number of pages is allocated to student
//       1 with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113.

// Solution: -

// The idea is to use Binary Search.
// We initialize minimum and maximum as 0 and sum-of-all-pages respectively.
// We fix a value for the number of pages as mid of current minimum and maximum.
// If a current mid can be a solution,
// then we search on the lower half, else we search in higher half.
// the main idea is to find a middle value, check if it can solve the problem.


// we need to check if we can assign pages to all students in a way
// that the maximum number doesn’t exceed current value.
// To do this, we sequentially assign pages to every student
// while the current number of assigned pages doesn’t exceed the value.
// In this process, if the number of students becomes more than m, then the solution is not feasible.
// Else feasible.

#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<int> arr, int n, int k, int mid)
{
    int curr_sum = 0;
    int stud_req = 1;
    
    for(int i=0; i<n; i++)
    {
            
        // if the new book cannot be allocated.
        // we need new student
        if(curr_sum + arr[i] > mid)
        {
            stud_req += 1;
            curr_sum = arr[i];
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    
    if(stud_req <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int findPages(vector<int> &arr, int k) 
{
    
    int sum = 0;
    int ans = INT_MAX;
    int n = arr.size();
    
    // more students to allocate than books
    if(k > n)
    {
        return -1;
    }
    
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    
    // The minimum number of pages a student can take is the largest book
    int left = *max_element(arr.begin(), arr.end());
    int right = sum;
    
    while(left <= right)
    {
        
        // consider allocating books = mid
        // we want to allocate only these many
        int mid = left + (right - left) / 2;
        
        // one of the solution, optimize further.
        if(is_possible(arr, n, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        
        // this is not a possible answer, so we can push left
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

// Driver code
int main()
{
    //Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of students
    return 0;
}
