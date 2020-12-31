#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximumToys(vector<int> &prices, int k) 
{
    sort(prices.begin(), prices.end());
    // for(auto x : prices)
    // {
    //     cout<<x<<" ";
    // }
    
    int net_prices = 0;
    int counter = 0;
    
    for(auto x : prices)
    {
        if((net_prices + x) > k)
        {
            break;
        }
        else
        {
            net_prices += x;
            counter += 1;
        }
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    vector <int> prices = {1, 12, 5, 111, 200, 1000, 10};
    int k = 50;
    cout<<maximumToys(prices, k);
    return 0;
}


