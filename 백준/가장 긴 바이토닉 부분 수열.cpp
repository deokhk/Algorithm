#include <iostream>
#include <algorithm>
using namespace std;
int sequence[1005];
int DPi[1005];
int DPd[1005];
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
		DPi[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sequence[i] > sequence[j] && DPi[j] + 1 > DPi[i])
			{
				DPi[i] = DPi[j] + 1;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		DPd[i] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (sequence[i] > sequence[j] && DPd[j] + 1 > DPd[i])
			{
				DPd[i] = DPd[j] + 1;
			}
		}
	}
	int maxv = DPi[0] + DPd[0]-1;
	for (int i = 0; i < N; i++)
	{
		maxv = max(maxv, DPi[i] + DPd[i]-1);
	}
	cout << maxv << endl;

}