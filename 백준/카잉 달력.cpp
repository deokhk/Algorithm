#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int x,int y)
{
	if(x>y)
	{
		int temp=x;
		int x=y;
		int y=temp;
	}
	if(y==0)
	{
		return x;
	}
	return gcd(y,x%y);
	
}
int LCM(int x,int y)
{
	return x*y/gcd(x,y);
}
int main()
{
	int T;
	cin>>T;
	for(int tn=0; tn<T; tn++)
	{
		int M,N,x,y;
		cin>>M>>N>>x>>y;
		int mvalue=max(M,N);
		int answer=0;
		int ispossible=false;
		int l=LCM(M,N);
		while(y!=1)
		{
			if(x==1)
			{
				x=M;
			}
			else
			{
				x--;
			}
			y--;
			answer++;
		}
		int year=0;
		int i=0;
		do
		{
			year=N*i+1;
			int tmp=(year%M);
			if(tmp==0)
			{
				if(x==M)
				{
					ispossible=true;
					break;
				}
			}
			else
			{
				if(tmp==x)
				{
					ispossible=true;
					break;
				}
			}
			i++;
		}while(year+answer<l);
		if(ispossible)
		{
			cout<<year+answer<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}
