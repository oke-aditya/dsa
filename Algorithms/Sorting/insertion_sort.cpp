// Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
// The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked an
// placed at the correct position in the sorted part.
// Algorithm
// To sort an array of size n in ascending order:
// 1: Iterate from arr[1] to arr[n] over the array.
// 2: Compare the current element (key) to its predecessor.
// 3: If the key element is smaller than its predecessor, compare it to the elements
// before. Move the greater elements one position up to make space for the swapped element.

// Time Complexity = O(N*N)

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


// This does insertion sort and converts array into sorted order (ascending)
void insertion_sort(vector<int> &arr)
{
    // We start inserting the first element, not 0th
    int i, j, ele;
    for (i = 1; i < arr.size(); i++)
    {
        ele = arr[i];
        // j is the previous element.
        j = i - 1;

        while (j >= 0 && arr[j] > ele)
        {
            // look for correct position of arr[i]
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j+1] = ele;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, -1, 4, 7, 0, 2, 33, 1};
    insertion_sort(arr);
    print_v(arr);

    return 0;
}
