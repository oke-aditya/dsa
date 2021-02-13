// Inversion Count for an array indicates –
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
// 


int main(int argc, char const *argv[])
{
    vector <int> v = {8, 4, 2, 1};

    cout<<count_inv_brute(v)<<endl;


    return 0;
}

