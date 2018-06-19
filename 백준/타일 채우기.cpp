#include <iostream>
using namespace std;
long long int DP[32];
int main()
{
	int n;
	cin >> n;
	DP[0] = 1;
	if (n % 2 == 0)
	{
		for (int i = 2; i <= n; i=i+2)
		{
			for (int j = 2; j <= i; j = j + 2)
			{
				DP[i] += 2 * DP[i - j];
			}
			DP[i] += DP[i - 2];
		}
		cout << DP[n] << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}