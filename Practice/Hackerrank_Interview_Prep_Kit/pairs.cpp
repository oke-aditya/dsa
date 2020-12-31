#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int pairs(int target, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = start + 1;
    int count = 0;

    while (end < arr.size())
    {
        int diff = arr[end] - arr[start];
        if(diff == target)
        {
            count += 1;
            end += 1;
        }
        else if(diff > target)
        {
            start +=1;
        }
        else if(diff < target)
        {
            end +=1;
        }
        // cout<<diff<<endl;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int k = 2;
    vector <int> v1 = {1, 5, 3, 4, 2};
    cout<<pairs(k, v1);

    return 0;
}

