#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==1)
	{
		printf("0\n");
	}
	else
	{
		int answer=pow(2,n/2);
		printf("%d\n",answer);
	}
}
