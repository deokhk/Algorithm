#include <iostream>
using namespace std;
void sp(int ssize,int blank);
int main()
{
	int n;
	scanf("%d",&n);
	sp(n);
}
void sp(int ssize,int blank)
{
	if(ssize==3 && !blank)
	{
		printf("***\n");
		printf("* *\n");
		printf("***\n");
		return;
	}
	if(blank)
	{
		for(int i=0; i<ssize; i++)
		{
			for(int j=0; j<ssize; j++)
			{
				printf(" ");
			}
			printf("\n");
		}
		return;
	}
	int nssize=ssize/3;
	sp(nssize, 
}
