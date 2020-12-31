// https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/

#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, string start_rod, string dest_rod, string help_rod)
{
    if(n == 1)
    {
        // We have only 1 rod.
        cout<<"Move 1 from "<<start_rod<<" to rod "<<dest_rod<<endl;
        return;
    }

    towerOfHanoi(n-1, start_rod, help_rod, dest_rod);
    cout<<"Move disk "<<n<<" from rod "<<start_rod<<" to rod "<<dest_rod<<endl;

    towerOfHanoi(n-1, help_rod, dest_rod, start_rod);

}


int main(int argc, char const *argv[])
{
    int n = 4;
    string help_rod = "H";
    string dest_rod = "D";
    string start_rod = "S";

    towerOfHanoi(n, "S", "D", "H");
    
    return 0;
}


