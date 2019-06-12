#include <iostream>
using namespace std;
long long fib[91];
int main()
{
	int n; 
	cin>>n;
	fib[0]=0;
	fib[1]=1;
	for(int i=2; i<=90; i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<<fib[n]<<endl;
}
