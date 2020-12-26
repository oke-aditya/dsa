#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    long long int F[32];
    int t, n;
    string st;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<32; i++)
        {
            F[i] = 0;
        }
        for(int i=1; i<=n; i++)
        {
            cin>>st;
            int mask=0;
            for(char ch : st)
            {
                if(ch == 'a')
                {
                    mask = mask | (1 << 0);
                }
                if(ch == 'e')
                {
                    mask = mask | (1 << 1);
                }
                if(ch == 'i')
                {
                    mask = mask | (1 << 2);
                }
                if(ch == 'o')
                {
                    mask = mask | (1 << 3);
                }
                if(ch == 'u')
                {
                    mask = mask | (1 << 4);
                }
            }
            F[mask] += 1;        
        }
        long long int result = 0;
        for(int i=1;i<32;i++)
        {
            for(int j=i+1; j<32; j++)
            {
                if((i | j) == 31)
                {
                    result = result + F[i] * F[j];
                }

            }
        }
        
        result = result + (F[31] * (F[31] - 1)) / 2;
        cout<<result<<endl;
    }
	return 0;
}
