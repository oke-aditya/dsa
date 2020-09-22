// Inversion Count for an array indicates – how far (or close) the array is from being sorted.
// If array is already sorted then inversion count is 0.
// If array is sorted in reverse order that inversion count is the maximum. 

// Two elements a[i] and a[j] form an inversion if 
// a[i] > a[j] and i < j. For simplicity, we may 
// assume that all elements are unique.

// Example:
// Input:  arr[] = {8, 4, 2, 1}
// Output: 6
// Given array has six inversions (8,4), (4,2),
// (8,2), (8,1), (4,1), (2,1).     

// Solution

// 1) Create an empty Set in C++ STL. 
//    And insert first element of array into the set.

// 2) Initialize inversion count as 0.

// 3) Iterate from 1 to n-1 and do following for every element in arr[i]
//      a) Insert arr[i] into the set.
//      b) Find the first element greater than arr[i] in set
//         using upper_bound() defined Set STL.
//      c) Find distance of above found element from last element in set
//         and add this distance to inversion count.

// 4) Return inversion count.

#include<iostream>
#include<set>
using namespace std;

void invcount(int arr[], int n)
{
    multiset<int> set1;
    set1.insert(arr[0]);
    
    int inv_count = 0;
    for(int i=1; i<n; i++)
    {
        set1.insert(arr[i]);
        // Set the iterator to first greater element than arr[i] 
        // in set (Note that set stores arr[0],.., arr[i-1] 
        auto itset1 = set1.upper_bound(arr[i]);

        // Get distance of first greater element from end 
        // and this distance is count of greater elements 
        // on left side of arr[i] 
        inv_count += distance(itset1, set1.end());
    }
    cout<<inv_count<<endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {8, 4, 2, 1};
    int n = 4;
    invcount(arr, n);
    return 0;
}

