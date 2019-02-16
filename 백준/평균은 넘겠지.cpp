#include <stdio.h>
int stu[1001];
int main()
{
	int c,n,j;
	scanf("%d",&c);
	for(int i=0; i<c; i++)
	{
		scanf("%d",&n);
		float avg=0;
		int up=0;
		for(j=0; j<n; j++)
		{
			scanf("%d",&stu[j]);
			avg+=stu[j];
		}
		avg/=n;
		for(j=0; j<n; j++)
		{
			if(avg<stu[j])
			{
				up++;
			}
		}
		float perc=((float)up/n)*100;
		printf("%.3f%%\n",perc);
	}
}
