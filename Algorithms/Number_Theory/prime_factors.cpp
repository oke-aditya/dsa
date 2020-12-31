#include<iostream>
using namespace std;

void prime_factors_brute(int n)
{
	// Time complexity = O(N) Even if it does not look by the code it is.
	for(int i=2; i<=n; i++)
	{
		if(n % i == 0)  // If i is a factor then
		{
			int cnt = 0; // Finding how many times it can divide it
			while(n % i == 0)
			{
				n /=  i;
				cnt += 1;
			}
			cout<<i<<" ^ "<<cnt<<endl;
		}
	}
}

void prime_factors_opt(int n)
{
	// If n is a composite number then there is at least 1 prime divisor of N
	// below sqrt(N)
	
	for(int i=2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			int cnt = 0;
			while(n % i == 0)
			{
				cnt += 1;
				n /= i;
			}
			cout<<i<<" ^ "<<cnt<<endl;
		}
	}
	if(n > 1)
	{
		cout<<n<<" ^ 1 "<<endl;	
	}
	
}


int main()
{
	int n;
	cin>>n;
	
//	prime_factors_brute(n);
	prime_factors_opt(n);
	
	return(0);
}




