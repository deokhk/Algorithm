#include <iostream>
using namespace std;
int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		bool isitdone = false;
		for (int i = 2; i <=n/2; i++)
		{
			bool isitprime = true;
			for (int j = 2; j*j <= i; j++)
			{
				if (i%j == 0)
				{
					isitprime = false;
					break;
				}
			}
			if (isitprime)
			{
				int k = n - i;
				bool isitprimea = true;
				for (int j = 2; j*j <= k; j++)
				{
					if (k%j == 0)
					{
						isitprimea = false;
						break;
					}
				}
				if (isitprimea)
				{
					isitdone = true;
					printf("%d = %d + %d\n",n, i, k);
				}
			}
			if (isitdone)
			{
				break;
			}
		}
		if (!isitdone)
		{
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
}