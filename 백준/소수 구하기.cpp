#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int M, N;
	int num = 0;
	scanf("%d",&M);
	scanf("%d", &N);
	for (int i = M; i <= N; i++)
	{
		bool isprime = true;
		if (i < 2)
		{
			isprime = false;
		}
		else
		{
			for (int j = 2; j*j <= i; j++)
			{
				if (i%j == 0)
				{
					isprime = false;
					break;
				}
			}
		}
		if (isprime)
		{
			printf("%d\n", i);
		}
	}
}
