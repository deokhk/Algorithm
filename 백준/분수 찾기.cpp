#include <iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	int numo=1;
	int deno=1;
	int i,j;
	for(i=1; 2*i*i+3*i<x-1; i++);
	deno+=2*(i-1);
	int rmmove=x-1-(2*(i-1)*(i-1)+3*(i-1));
	for(j=1; j<=rmmove;j++)
	{
		if(j==1)
		{
			deno++;
		}
		else if(1<j && j<=2*i)
		{
			deno--;
			numo++;
		}
		else if(j==2*i+1)
		{
			numo++;
		}
		else
		{
			deno++;
			numo--;
		}
	}
	cout<<numo<<'/'<<deno;
}
