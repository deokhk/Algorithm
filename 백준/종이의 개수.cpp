#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int map[2188][2188];
int n;
int minusone = 0;
int zero = 0;
int one = 0;
void split(int dia,int centerx, int centery);
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	split(n, n/2, n/2);
	printf("%d\n%d\n%d\n", minusone, zero, one);
}
void split(int dia,int centerx,int centery)
{
	if (dia == 1)
	{
		if (map[centery][centerx] == 0)
		{
			zero++;
		}
		else if (map[centery][centerx] == 1)
		{
			one++;
		}
		else
		{
			minusone++;
		}
	}
	else
	{
		bool same = true;
		int cen = map[centery][centerx];
		for (int i = -(dia/2); i <= dia/2; i++)
		{
			for (int j = -(dia/2); j <= dia /2; j++)
			{
				if (cen != map[centery + i][centerx + j])
				{
					same = false;
					break;
				}
			}
			if (!same)
			{
				break;
			}
		}
		if (same)
		{
			if (cen == 0)
			{
				zero++;
			}
			else if (cen == 1)
			{
				one++;
			}
			else
			{
				minusone++;
			}
		}
		else
		{
			int dx[3] = { -1 * dia/3,0,1 * dia/3 };
			int dy[3] = { -1 *dia/3,0,1 * dia/3 };
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					split(dia / 3, centerx + dx[i], centery + dy[j]);
				}
			}
		}
	}
}