// https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/

#include <bits/stdc++.h>
using namespace std;

void powerSet(string str, int index = 0, string curr = "")
{
    int n = str.length();

    // Base case
    if(index == n)
    {
        cout<<curr<<endl;
        return;
    }

    // Either we can choose the character or avoid it
    powerSet(str, index+1, curr + str[index]);
    powerSet(str, index+1, curr);

}

int main(int argc, char const *argv[])
{
    string str = "abc";
    powerSet(str);
    return 0;
}
