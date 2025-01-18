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
// We fix a value for the number of pages as mid of current minimum and maximum.
// We initialize minimum and maximum as 0 and sum-of-all-pages respectively.
// If a current mid can be a solution,
// then we search on the lower half, else we search in higher half.

// we need to check if we can assign pages to all students in a way
// that the maximum number doesn’t exceed current value.
// To do this, we sequentially assign pages to every student
// while the current number of assigned pages doesn’t exceed the value.
// In this process, if the number of students becomes more than m, then the solution is not feasible.
// Else feasible.

#include <bits/stdc++.h>

using namespace std;

bool is_possible(int arr[], int n, int m, int curr_min)
{
    int curr_sum = 0;
    int stud_req = 1;

    // iterate all over
    for (int i = 0; i < n; i++)
    {
        // check if current number of pages are greater.
        // current min will get result
        if (arr[i] > curr_min)
        {
            return false;
        }

        // count how many students are required
        // to distribute current min
        if (curr_sum + arr[i] > curr_min)
        {
            // increment student count
            stud_req += 1;

            // if students required becomes greater than given no, return false
            if (stud_req > m)
            {
                return false;
            }
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    return true;
}

int find_pages(int arr[], int n, int m)
{
    int sum = 0;

    // If no of books < no of students.
    if (n < m)
    {
        return -1 ;
    }
    // Count total number of pages
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // Initialize start as 0 and pages end as total pages
    int start = 0, end = sum;
    int result = INT_MAX;

    // traverse until start <= end
    while (start <= end)
    {
        // Check if it is possible to distribute
        // Books by using mid as current min
        int mid = (start + end) / 2;
        if (is_possible(arr, n, m, mid))
        {
            // If yes then calculate minimum of result
            result = min(result, mid);

            // We are finding min and books are sorted so reduce end=mid-1
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    // Return minimum no of pages.
    return result;
}

// Driver code
int main()
{
    //Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of students

    cout << "Minimum number of pages = " << find_pages(arr, n, m) << endl;
    return 0;
}
