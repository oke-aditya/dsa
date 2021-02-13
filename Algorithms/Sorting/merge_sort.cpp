// Merge Sort

// MergeSort(arr[], l,  r)
// If r > l
//      1. Find the middle point to divide the array into two halves:  
//              middle m = l+ (r-l)/2
//      2. Call mergeSort for first half:   
//              Call mergeSort(arr, l, m)
//      3. Call mergeSort for second half:
//              Call mergeSort(arr, m+1, r)
//      4. Merge the two halves sorted in step 2 and 3:
//              Call merge(arr, l, m, r)

#include<bits/stdc++.h>
using namespace std;

void print_v(vector <int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void merge(vector <int> &v, int l, int m, int r)
{
    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    int n1 = m - l + 1;
    int n2 = r - m ;

    // Create two empty vectors
    vector <int> left(n1);
    vector <int> right(n2);

    // Copy data to left.
    for(int i=0; i<n1; i++)
    {
        left[i] = v[l + i];
    }

    for(int j=0; j<n2; j++)
    {
        right[j] = v[m + j + 1];
    }

    // Now it is a simple merge of two arrays in O(n) time.
    // Merge the temp arrays back into arr[l..r]
    int i=0, j=0, k = l;
    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            v[k] = left[i];
            i += 1;
        }
        else
        {
            v[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    while(i < n1)
    {
        v[k] = left[i];
        i += 1;
        k += 1;
    }

    while(j < n2)
    {
        v[k] = right[j];
        j += 1;
        k += 1;
    }
}


void merge_sort(vector <int> &v, int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

int main(int argc, char const *argv[])
{
    vector <int> v = {1, 3, 2, 5, 4, 7};
    print_v(v);
    merge_sort(v, 0, v.size() - 1);
    print_v(v);

    return 0;
}


