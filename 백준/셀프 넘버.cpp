#include <iostream>
using namespace std;
int numb[10000];
 gnt(int n);
int main()
{
	for(int i=0; i<10000; i++)
	{
		if(!numb[i])
		{
			gnt(i+1);
		}
	}
	for(int i=0; i<10000; i++)
	{
		if(!numb[i])
		{
			printf("%d\n",i+1);
		}
	}
}
void gnt(int n)
{
	int x=0;
	int res=n;
	while(n!=0)
	{
		x=n%10;
		n/=10;
		res+=x;
	}
	if(res<=10000)
	{numb[res-1]=1;
	gnt(res);
	}
}
