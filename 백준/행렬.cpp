#include <iostream>
#include <cstdio>
using namespace std;
int mapA[51][51];
int mapB[51][51];
int main()
{
	int n, m;
	scanf("%d",&n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d",&mapA[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d",&mapB[i][j]);
		}
	}
	int flip = 0;
	for (int i = 0; n>2 && i < n-2; i++)
	{
		for (int j = 0; m>2 && j<m-2; j++)
		{
			if (mapA[i][j] != mapB[i][j])
			{
				for (int k = i; k < i + 3; k++)
				{
					for (int l = j; l < j + 3; l++)
					{
						mapA[k][l] = mapA[k][l] == 1 ? 0 : 1;
					}
				}
				flip++;
			}
		}
	}
	bool possible = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mapA[i][j] != mapB[i][j])
			{
				possible = false;
				break;
			}
		}
	}
	if (possible)
	{
		printf("%d\n",flip);
	}
	else
	{
		printf("-1\n");
	}
}