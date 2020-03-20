// Used to calculated a ^ n

#include<iostream>
using namespace std;

int brute_exp(int a, int n)
{
	int result = 1;
	for(int i=0; i<n; i++)
	{
		result *= a;
	}
	return result;
}

int opt_exp(int a, int n)
{
	// Time complexity = O(log(n))
	int result = 1;
	while(n>0)
	{
		if(n % 2 == 0)
		{
			a *= a;
			n /= 2;
		}
		else
		{
			result *= a;
			n -= 1;
		}
	}
	return result;
}

int mod_exp(int a, int n, int p)
{
	// Used to calculate a^n % p
	// Time complexity = O(log(n))
	int result = 1;
	while(n>0)
	{
		if(n % 2 == 0)
		{
			a = (a * a) % p;
			n /= 2;
		}
		else
		{
			result = (result * a) % p;
			n -= 1;
		}
	}
	return result;
}

int main()
{
	int a,n,p,res,res2,res3;
	cin>>a;
	cin>>n;
	cin>>p;
	res = brute_exp(a, n);
	cout<<endl<<res;
	res2 = opt_exp(a, n);
	cout<<endl<<res2;
	res3 = mod_exp(a, n, p);
	cout<<endl<<res3;
	return(0);
}


