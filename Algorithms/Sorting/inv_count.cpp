// Inversion Count for an array indicates –
// https://www.geeksforgeeks.org/counting-inversions/

// how far (or close) the array is from being sorted.
// If array is already sorted then inversion count is 0.
// If array is sorted in reverse order that inversion count is the maximum. 
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 

// Input: arr[] = {8, 4, 2, 1}
// Output: 6

// Explanation: Given array has six inversions:
// (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

#include<bits/stdc++.h>
using namespace std;

int count_inv_brute(vector <int> v)
{
    int n = v.size(), count=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(v[i] > v[j])
            {
                count += 1;
            }
        }
    }
    return count;
}

// Optimal Solution: -

// This involves the concept of merge sort.
// While merging in merge sort, we need to check 
// In merge process, let i is used for indexing left sub-array and j
// for right sub-array. At any step in merge(),
// if a[i] is greater than a[j], then there are (mid – i) inversions.
// because left and right subarrays are sorted,
// so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

// Create a function merge that counts the number of
// inversions when two halves of the array are merged, create two indices i and j,
// i is the index for first half and j is an index of the second half. if a[i]
// is greater than a[j], then there are (mid – i) inversions. because left and 
// right subarrays are sorted, so all the remaining elements in
// left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
// Create a recursive function to divide the array into halves and find the answer
// by summing the number of inversions is the first half, number of inversion
// in the second half and the number of inversions by merging the two.

int count_inv_opt(vector <int> v)
{
    
}


int main(int argc, char const *argv[])
{
    vector <int> v = {8, 4, 2, 1};

    cout<<count_inv_brute(v)<<endl;

    cout<<count_inv_opt(v)<<endl;


    return 0;
}

