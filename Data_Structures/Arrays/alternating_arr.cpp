#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve_on2()
{
    int t;
    int n;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0; i<n; i++)
        {
            int count = 1,curr;
            if(arr[i] < 0)
            {
                curr = -1;
            }
            else
            {
                curr = 1;
            }
            for(int j=i+1; j<n; j++)
            {
                if(curr == -1)
                {
                    if(curr * arr[j] < 0)
                    {
                        curr = 1; 
                        count += 1;    
                    }
                    else
                    {
                        break;
                    }
                }
                else if(curr == 1)
                {
                    if(curr * arr[j] < 0)
                    {
                        curr = -1;
                        count += 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
             cout<<count<<" ";
        }
        cout<<endl;
        t -= 1;
    }
    
}

void solve_on()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        vector <long long int> arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        vector <int> ans(n);
        ans[n-1] = 1;
        int count = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1] > 0 && arr[i] < 0  || arr[i+1] < 0 && arr[i] > 0)
            {
                ans[i] = ans[i+1] + 1;
            }
            else
            {
                ans[i] = 1;
            }
        }
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        t -= 1;
    }
}

int main() 
{
    // O(n2) approach
    // solve_on2();

    // O(n) approach
    solve_on();
	return 0;
}
