#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int check[20005];
bool ispossible = true;
void bfs(int x, vector<vector<int>> &u);
int main()
{
	int k;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %d", &n, &m);
		vector<vector<int>> a(n + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				check[i] = 1;
				bfs(i, a);
			}
			if (!ispossible)
			{
				break;
			}
		}
		for (int i = 1; i <=n; i++)
		{
			check[i] = 0;
		}
		if (ispossible)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		ispossible = true;
	}
}
void bfs(int i, vector<vector<int>> &u)
{
	for (int j = 0; j < u[i].size(); j++)
	{
		if (check[u[i][j]] == 0)
		{
			if (check[i] == 1)
			{
				check[u[i][j]] = 2;
				bfs(u[i][j], u);
			}
			else
			{
				check[u[i][j]] = 1;
				bfs(u[i][j], u);
			}
		}
		else
		{
			if (check[i] == check[u[i][j]])
			{
				ispossible = false;
			}
		}
	}
}
