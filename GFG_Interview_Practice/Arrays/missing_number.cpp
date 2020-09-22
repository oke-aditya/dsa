// Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, 
// the missing number is to be found.

// Input:
// The first line of input contains an integer T denoting the number of test cases. 
// For each test case first line contains N(size of array). 
// The subsequent line contains N-1 array elements.

#include<iostream>
#include<vector>
using namespace std;

void find_miss(vector<int> v, int n)
{
    // Find sum of array
    int sum=0;
    for (auto x : v)
    {
        sum += x;
    }
    int sum2 = (n * (n+1)) / 2;
    cout<<(sum2 - sum)<<endl;
}

int main(int argc, char const *argv[])
{
    vector <int> v1 = {1, 2, 3, 5};
    int n1 = 5;
    vector <int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int n2 = 10;

    find_miss(v1, n1);
    find_miss(v2, n2);

    return 0;
}

