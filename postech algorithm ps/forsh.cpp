#include <iostream>
#include <algorithm>
using namespace std;
int array[1005];
int main()
{
	int t;
	scanf("%d", &t);
	for(int tn=0; tn<t; tn++)
	{
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf("%d",&array[i]);
		}
		sort(array,array+N);
		for(int i=0; i<N; i++)
		{
			printf("%d ",array[i]);
		}
		printf("\n");
	}
}
