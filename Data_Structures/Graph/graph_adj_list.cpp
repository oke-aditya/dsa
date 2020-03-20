#include<iostream>
using namespace std;

int main()
{
	// N is number of nodes
	// M is number of edges
	vector<int> ar[n+1];

	while(m--)
	{
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	return(0);
}
