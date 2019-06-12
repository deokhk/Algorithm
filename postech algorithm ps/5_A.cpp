#include <iostream>
#include <vector>
using namespace std;
long long maxv[3001][3001];
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		vector<vector<int> > grid(N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				grid[i].push_back(tmp);
			}
		}
		for (int i = 0; i < N; i++)
		{
			//leftmax
			if (i == 0)
			{
				maxv[0][0] = grid[0][0];
				for (int j = 1; j < M; j++)
				{
					maxv[0][j] = maxv[0][j - 1] + grid[0][j];
				}
			}
			else
			{
				vector<long long> left(M);
				vector<long long> right(M);
				left[0] = maxv[i - 1][0]+grid[i][0];
				right[M - 1] = maxv[i - 1][M - 1]+grid[i][M-1];
				for (int j = 1; j < M; j++)
				{
					left[j] = (maxv[i - 1][j]+grid[i][j]) > (left[j - 1] + grid[i][j]) ? (maxv[i - 1][j]+grid[i][j]) : (left[j - 1] + grid[i][j]);
				}
				for (int j = M-2; j >= 0; j--)
				{
					if (j >= 0)
					{
						right[j] = (maxv[i - 1][j]+grid[i][j]) > (right[j + 1] + grid[i][j]) ? (maxv[i - 1][j]+grid[i][j]) : (right[j + 1] + grid[i][j]);
					}
				}
				for (int j = 0; j < M; j++)
				{
					maxv[i][j] = left[j] > right[j] ? left[j] : right[j];
				}
			}
		}
		long long ans = maxv[N - 1][M - 1];
		printf("%lld\n", ans);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				maxv[i][j] = 0;
			}
		}
	}
}