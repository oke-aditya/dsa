#include<iostream>
using namespace std;

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    int t, n;
    cin>>t;
    while(t--)
    {
        cin >> n;                  // No of elements in the set
        int tot = 1 << n;          // Total number of subsets = 2^n
        for(int mask=0; mask<tot; mask++)    // Totally 2^N elements to check
        {
            for(int i=0; i<n; i++) // For every number n. Check which bit is set to 1.
            {
                int f = 1 << i;
                if((mask & f) != 0)          // Do not forget the bracket
                {
                    // print i th element;
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;
        }
    }
}