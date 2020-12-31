#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void whatFlavors(vector <int> arr, int money) 
{
    // Complete this function
    int first_pick = 0;
    int second_pick;
    unordered_map<int,int> cost;

    for(int i=0;i<arr.size();i++)
    {
        second_pick = i;
        int chk = money-arr[i];

        if(cost.count(chk))
        {
            first_pick = cost[chk];
            cout<<first_pick+1<<" "<<second_pick+1<<endl;
            return;
        }
        cost[arr[i]]=i;
    }
}

int main(int argc, char const *argv[])
{
    vector <int> nums = {3, 2, 4};
    int target = 6;

    whatFlavors(nums, target);

    return 0;
}

