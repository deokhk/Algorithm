#include <iostream>
#include <queue>
int map[105][105];
int check[105][105];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
using namespace std;
int main()
{
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}
	queue<pair<int, int>> mapcheck;
	mapcheck.push(make_pair(1, 1));
	int answer = 1;
	while (!mapcheck.empty())
	{
		pair<int, int> temp = mapcheck.front();
		mapcheck.pop();
		for (int k = 0; k < 4; k++)
		{
			int x = temp.first + dx[k]; int y = temp.second + dy[k];
			if (map[x][y] == 1 && check[x][y] == 0)
			{
				check[x][y] = check[temp.first][temp.second] + 1;
				mapcheck.push(make_pair(x, y));

			}
		}
	}
	printf("%d\n",check[n][m]+1);

}
