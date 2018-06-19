#include <iostream>
#include <algorithm>
using namespace std;
int DP[305][2];
int stair[305];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}
	DP[1][1] = stair[1];
	DP[1][2] = stair[1];
	for (int i = 2; i <= N; i++)
	{
		DP[i][1] = max(DP[i - 2][1], DP[i - 2][2]) + stair[i];
		DP[i][2] = DP[i - 1][1] + stair[i];
	}
	cout << max(DP[N][1], DP[N][2]) << endl;
}