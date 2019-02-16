#include <iostream>
using namespace std;
int A[1005][1005];
bool check[1005];
int n;
void dfs(int x);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int v;
			cin >> v;
			A[i][v] = 1;
		}
		int answer = 0;
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == false)
			{
				dfs(i);
				answer++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				A[i][j] = 0;
			}
			check[i] = false;
		}
		cout << answer << endl;
	}
}
void dfs(int x)
{
	check[x] = true;
	for (int i = 1; i <= n; i++)
	{
		if (A[x][i] == 1 && check[i] == false)
		{
			dfs(i);
		}
	}
}