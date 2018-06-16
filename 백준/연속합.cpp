#include <iostream>
#include <algorithm>
using namespace std;
int sequence[100005];
int DP[100005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sequence[i]);
	}
	DP[0] = sequence[0];
	int maxv = DP[0];
	for (int i = 1; i < n; i++)
	{
		DP[i] = sequence[i];
		if (DP[i - 1] > 0)
		{
			DP[i] = DP[i] + DP[i - 1];
		}
		maxv = max(maxv, DP[i]);
	}
	cout << maxv << endl;
}