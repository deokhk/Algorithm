#include <iostream>
#include <algorithm>
using namespace std;
int li[1001];
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++)
	{
		int tn;
		scanf("%d",&tn);
		for(int j=0; j<tn; j++)
		{
			scanf("%d", &li[j]);
		}
		sort(li,li+tn);
		for(int j=0; j<tn; j++)
		{
			printf("%d ", li[j]);
		}
		printf("\n");
	}
}
