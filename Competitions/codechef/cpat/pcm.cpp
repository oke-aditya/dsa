#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    unordered_set<string> st;
    while (n > 0)
    {
        cin >> s;
        bool cflag = false, mflag = false, pflag = false;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == 'P')
            {
                pflag = true;
            }
            else if(s[i] == 'C')
            {
                cflag = true;
            }
            else if(s[i] == 'M')
            {
                mflag = true;
            }
        }
        if(cflag && mflag && pflag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
