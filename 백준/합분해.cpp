#include <iostream>
using namespace std;
long long int DP[205][205];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
	{
		DP[i][1] = 1;
		for (int j = 2; j <= K; j++)
		{
			for (int k = 0; k <= i; k++)
			{
				DP[i][j]=DP[i][j]+DP[i - k][j - 1];
				DP[i][j] %=1000000000;//mod 연산은 맨마지막에 해주자.
			}
		}
	}
	cout << DP[N][K] << endl;
}