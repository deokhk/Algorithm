#include <iostream>
#include <algorithm>
using namespace std;
int sequence[1005];
int DP[1005];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}
	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sequence[i] < sequence[j])
			{
				DP[i] = max(DP[j] + 1, DP[i]);
			}
		}
	}
	int maxv = DP[0];
	for (int i = 0; i < N; i++)
	{
		maxv = max(maxv, DP[i]);
	}
	cout << maxv << endl;
}