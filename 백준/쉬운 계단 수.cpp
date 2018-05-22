#include <iostream>
using namespace std;
int memo[101][11];
int calmem(int n,int i);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)
	{
		memo[1][i] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 0 || i==1 || i==9)
		{
			memo[2][i] = 1;
		}
		else
		{
			memo[2][i] = 2;
		}
	}
	long long sum = 0;
	
	for (int k = 0; k < 10; k++)
	{
	sum += calmem(n, k);
	}
	sum = sum % 1000000000;
	cout << sum << endl;;
}
int calmem(int n, int i)
{
	if (memo[n][i] > 0 || n==1)
	{
		return memo[n][i];
	}
	else
	{
		if (i == 0)
		{
			memo[n][i] = calmem(n - 1, 1) % 1000000000;
		}
		else if(i==9)
		{
			memo[n][i] = calmem(n - 1, 8) % 1000000000;
		}
		else
		{
			memo[n][i] = (calmem(n - 1, i + 1) + calmem(n - 1, i - 1)) % 1000000000;
		}
		return memo[n][i];
	
	}
}