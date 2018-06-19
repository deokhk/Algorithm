#include <iostream>
#include <algorithm>
using namespace std;
int DP[100005];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		DP[i] = DP[i - 1] + 1;
		for (int j = 2; j*j <= i; j++)
		{
			DP[i] = min(DP[i], DP[i - j*j] + 1);
		}
	}
	cout << DP[N] << endl;

}