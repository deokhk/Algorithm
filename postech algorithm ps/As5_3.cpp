#include <iostream>
using namespace std;
int arr[3004][3004];
long long DP[3004][3004];
int main()
{
	int t;
	scanf("%d", &t);
	for (int tn = 0; tn < t; tn++)
	{
		int N, M, d;
		scanf("%d %d %d", &N, &M, &d);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				DP[i][j] = DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1] + arr[i][j];
			}
		}
		for (int i = 1; i <= N - d + 1; i++)
		{
			for (int j = 1; j <= M - d + 1; j++)
			{
				long long res = DP[i + d-1][j + d-1] - DP[i + d-1][j-1] - DP[i-1][j + d-1] + DP[i-1][j-1];
				printf("%lld ", res);
			}
			printf("\n");
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				arr[i][j] = 0;
				DP[i][j] = 0;
			}
		}
	}
}