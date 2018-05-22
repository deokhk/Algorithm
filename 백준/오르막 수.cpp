#include <iostream>
using namespace std;
int num[1000][10];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		num[1][i] = 1;
	}
	for (int j = 2; j <= n; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i <= k; i++)
			{
				num[j][k] += num[j - 1][i];
			}
			num[j][k]%=10007;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += num[n][i];
	}
	sum %=10007;
	cout << sum << endl;
}