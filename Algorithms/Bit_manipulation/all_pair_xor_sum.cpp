#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int res = 0, n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    // For every signed 32 bit 
    for(int i=0; i<31; i++)
    {
        int cntz = 0, cnto = 0;
        for(int j=0; j<n; j++)
        {
            if(arr[j] & (1 << i))
            {
                // if ith bit is one
                cnto += 1;
            }
            else
            {
                // if ith bit is zero
                cntz += 1;
            }
        }
        int pairs = cntz * cnto;
        res += (1 << i) * pairs;
    }
    cout<<res;
    return(0);
}