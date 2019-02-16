#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, m;
int A[1003][1003];
bool checkb[1003];
bool checkd[1003];
void dfs(int x);
int main()
{
	int start;
	scanf("%d %d %d",&n,&m,&start);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);
		A[u][v] = A[v][u] = 1;
	}
	dfs(start);
	printf("\n");
	queue<int> q;
	q.push(start);
	checkb[start] = true;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		printf("%d ", temp);
		for (int i = 1; i <= n; i++)
		{
			if (A[temp][i] == 1 && checkb[i] == false)
			{
				checkb[i] = true;
				q.push(i);
			}
		}
	}
	printf("\n");
}
void dfs(int x)
{
	checkd[x] = true;
	printf("%d ",x);
	for (int i = 1; i <= n; i++)
	{
		if (A[x][i] == 1 && checkd[i] == false)
		{
			dfs(i);
		}
	}
}