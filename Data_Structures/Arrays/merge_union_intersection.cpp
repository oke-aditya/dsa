// Merge, Union and Intersection of two sorted arrays

// Given two sorted arrays, find their merge, union and intersection

// Input : arr1[] = {1, 3, 4, 5, 7}
//         arr2[] = {2, 3, 5, 6}
// Output : Union : {1, 2, 3, 4, 5, 6, 7}
//          Intersection : {3, 5}

// Input : arr1[] = {2, 5, 6}
//         arr2[] = {4, 6, 8, 10}
// Output : Union : {2, 4, 5, 6, 8, 10}
//          Intersection : {6}

// All should have O(n+m) time complexity

#include <iostream>
using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr1[], int n, int arr2[], int m)
{
    int i = 0;
    int j = 0;
    int ind = 0;
    int temp_arr[m + n];

    while ((i + j) < (m + n))
    {
        if (i == n)
        {
            temp_arr[ind] = arr2[j];
            ind += 1;
            j += 1;
        }
        else if (j == m)
        {
            temp_arr[ind] = arr1[i];
            ind += 1;
            i += 1;
        }
        else
        {
            if (arr1[i] <= arr2[j])
            {
                temp_arr[ind] = arr1[i];
                ind += 1;
                i += 1;
            }
            else if (arr1[i] > arr2[j])
            {
                temp_arr[ind] = arr2[j];
                ind += 1;
                j += 1;
            }
        }
    }
    print_arr(temp_arr, (m + n));
}

void union_arr(int arr1[], int n, int arr2[], int m)
{
    // int arr_un[100];
    int i = 0;
    int j = 0;
    while ((i + j) < (m + n))
    {
        if (j == m)
        {
            cout << arr1[i] << " ";
            i += 1;
        }
        else if (i == n)
        {
            cout << arr2[j] << " ";
            j += 1;
        }
        else
        {
            if (arr1[i] < arr2[j])
            {
                cout << arr1[i] << " ";
                i += 1;
            }
            else if (arr1[i] > arr2[j])
            {
                cout << arr2[j] << " ";
                j += 1;
            }
            else
            {
                cout << arr1[i] << " ";
                i += 1;
                j += 1;
            }
        }
    }
    cout << endl;
}

void intersection(int arr1[], int n, int arr2[], int m)
{
    int arr_int[100];
    int i = 0;
    int j = 0;
    while ((i + j) < (m + n))
    {
        if (arr1[i] < arr2[j])
        {
            i += 1;
        }
        else if (arr1[i] > arr2[j])
        {
            j += 1;
        }
        else
        {
            cout << arr1[i] << " ";
            i += 1;
            j += 1;
        }
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 3, 5, 6};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, n, arr2, m);
    union_arr(arr1, n, arr2, m);
    intersection(arr1, n, arr2, m);
    return (0);
}
