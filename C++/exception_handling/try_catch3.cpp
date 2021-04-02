#include<bits/stdc++.h>

using namespace std;

double divide ( double a, double b)
{
	if ( b == 0 ) // !! Division by zero
    	throw "Division by zero";
    else
    	return a / b;
}

int main(int argc, char const *argv[])
{
    vector <int> v;
    v.push_back(0);
    v.push_back(1);

    try
    {
        v.at(2);
    }
    catch(const exception& e)
    {
        cout<<"Error occured"<<endl;
    }

    try
    {
        double res = divide(1, 0);
    }
    catch(const char *c)
    {
        cout<<c;
    }
    

    return 0;
}

