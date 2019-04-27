#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n,int x,int y);
int main()
{
	int N;
	scanf("%d",&N);
	int tot=pow(2,N)-1;
	printf("%d\n",tot);
	hanoi(N,1,3);
}
void hanoi(int n,int x,int y)
{
	if(n==0)
	{
		return;
	}
	hanoi(n-1, x, 6-x-y);
	printf("%d %d\n",x,y);
	hanoi(n-1,6-x-y,y);
	
}
