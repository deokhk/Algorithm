#include <iostream>
using namespace std;
int N, M;
int A[1005][1005];
int check[1005];
void bfs(int x);
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		A[u][v] = A[v][u] = 1;
	}
	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0)
		{
			bfs(i);
			num++;
		}
	}
	cout << num << endl;

}
void bfs(int x)
{
	check[x] = 1;
	for (int i = 0; i <= N; i++)
	{
		if (A[x][i] == 1 && check[i] == 0)
		{
			bfs(i);
		}
	}
}