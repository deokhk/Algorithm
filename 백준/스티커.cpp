#include <iostream>
int field[2][100005];
long long memo[2][100005];
using namespace std;
void calmax(int pos);
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&field[0][i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&field[1][i]);
		}
		for (int i = 0; i < n; i++)
		{
			calmax(i);
		}
		long long result = memo[0][n - 1] > memo[1][n - 1] ? memo[0][n - 1] : memo[1][n - 1];
		cout << result << endl;
		//initialize memo array
		for (int i = 0; i < n; i++)
		{
			memo[0][i] = 0;
			memo[1][i] = 0;
		}
	}
	return 0;
}
void calmax(int pos)
{
	if (pos == 0)
	{
		memo[0][pos] = field[0][pos];
		memo[1][pos] = field[1][pos];
	}
	else
	{
		if (memo[1][pos - 1] + field[0][pos] > memo[0][pos - 1])
		{
			memo[0][pos] = memo[1][pos - 1] + field[0][pos];
		}
		else
		{
			memo[0][pos] = memo[0][pos - 1];
		}
		if (memo[0][pos - 1] + field[1][pos] > memo[1][pos - 1])
		{
			memo[1][pos] = memo[0][pos - 1] + field[1][pos];
		}
		else
		{
			memo[1][pos] = memo[1][pos - 1];
		}
	}
}