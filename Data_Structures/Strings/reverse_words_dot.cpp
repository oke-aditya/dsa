#include <iostream>
using namespace std;

int main() {
    string s1;
    char cmp = '.';
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1;
        string temp = "";
        for(int i=0; i<s1.length();i++)
        {
            if(s1[i] == cmp)
            {
                for(int j=temp.length(); j>=0; j--)
                {
                    cout<<temp[j];
                }
                temp = "";
                cout<<".";
            }
            else
            {
                temp += s1[i];
            }
        }
        for(int k=temp.length(); k>=0; k--){
        cout<<temp[k];
        }
        cout<<endl;
    }
	return 0;
}