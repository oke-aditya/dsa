// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
// We have to paint n boards of length {A1, A2, .. An}. There are k painters available 
// and each takes 1 unit time to paint 1 unit of board. 
// The problem is to find the minimum time to get this job done 
// under the constraints that any painter will only paint continuous 
// sections of boards, say board {2, 3, 4} 
// or only board {1} or nothing but not board {2, 4, 5}.

// Input : k = 2, A = {10, 10, 10, 10} 
// Output : 20.
// Here we can divide the boards into 2
// equal sized partitions, so each painter 
// gets 20 units of board and the total
// time taken is 20. 

// Input : k = 2, A = {10, 20, 30, 40} 
// Output : 60.
// Here we can divide first 3 boards for
// one painter and the last board for 
// second painter

// Solution: -
// The idea is again to find pivot element here.
// We should search for the pivot from 0 to sum of elements.


#include<bits/stdc++.h>
using namespace std;

int sum_arr(int arr[], int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int is_possible(int arr[], int n, int k, int curr_min)
{

    int curr_sum = 0;
    int pain_req = 1;

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
            pain_req += 1;

            // if students required becomes greater than given no, return false
            if (pain_req > k)
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



int find_painters(int arr[], int n, int k)
{
    int start = 0;
    int end = sum_arr(arr, n);
    int result = INT_MAX;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(is_possible(arr, n, k, mid))
        {
            result = min(result, mid);

            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        
    }
    return result;

}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout<<find_painters(arr, n, k)<<endl;

    return 0;
}


