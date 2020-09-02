#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    auto diff = INT_MAX;
    
    // from 1st element to last.
    auto start_itr = next(arr.begin());

    for(auto i=start_itr; i!= arr.end(); i++)
    {
        diff = min(diff, (*i - *prev(i)));
    }
    
    return diff;
}

int main(int argc, char const *argv[])
{
    // vector<int> arr = {1, -3, 71, 68, 17};
    // vector<int> arr = {-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
    vector<int> arr = {3, -7, 0};

    auto res = minimumAbsoluteDifference(arr);
    cout<<res;

    return 0;
}

