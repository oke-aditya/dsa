#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() 
{
    ll int t,n,k,i,cpyn;
    // memset(arr, 0, sizeof(arr));
    cin>>t;
    while(t--)
    {
        ll int arr[1000001] = {0};
        cin>>n;
        cpyn = n;
        while(n--)
        {
            cin>>k;
            arr[k] += 1;
        }
        int fg = 1;
        // if(cpyn % 2 == 1)
        // {
        //     cpyn += 1;
        // }
        for(i=0; i<1000001; i++)
        {
            if(float(arr[i]) > (cpyn/2))
            {
                cout<<i<<endl;
                fg = 0;
                break;
            }
        }
        if(fg==1)
        {
            cout<<"-1"<<endl;
        }
    }

	//code
	return 0;
}