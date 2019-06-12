#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int house[1000003];
int main()
{
	int t;
	scanf("%d",&t);
	for(int tn=0; tn<t; tn++)
	{
		int n;
		long long int dissum=0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&house[i]);
		}
		if(n%2==0)
		{
			long long int dissum1=0;
			long long int dissum2=0;
			int centerl=house[(n/2)-1];
			int centerr=house[n/2];
			for(int i=0; i<n; i++)
			{
			dissum1+=abs(centerl-house[i]);
			dissum2+=abs(centerr-house[i]);
			}
			dissum=dissum1 > dissum2 ? dissum2 : dissum1;
		}
		else
		{
			int center=house[n/2];
		for(int i=0; i<n; i++)
		{
			dissum+=abs(center-house[i]);
		}
		}
		printf("%lld\n",dissum);
	}
}
