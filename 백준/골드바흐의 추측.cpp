#include <iostream>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		bool isitdone = false;
		for (int i = n / 2; i > 1; i--)
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
					printf("%d %d\n", i, k);
				}
			}
			if (isitdone)
			{
				break;
			}
		}
	}
}