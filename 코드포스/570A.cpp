#include <iostream>
using namespace std;
bool isint(int n)
{
	int sum=0;
	while(n>0)
	{
		sum+=(n%10);
		n/=10;
	}
	if(sum%4==0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int main()
{
	int a;
	cin>>a;
	while(!isint(a))
	{
		a++;
	}
	cout<<a<<endl;
}
