#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
int map[105][105];
int check[105][105];
int d[105][105];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,-0,1,0 };
void dfs(int i, int j, int islandnum);
queue<pair<int, int>> res;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	int isl = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] && !check[i][j])
			{
				dfs(i, j, isl);
				isl++;
			}
		}
	}
	while (!res.empty())
	{
		pair<int, int> temp = res.front();
		res.pop();
		for (int k = 0; k < 4; k++)
		{
			int x = temp.first + dx[k]; int y = temp.second + dy[k];
			if (d[x][y] == -1)
			{
				d[x][y] = d[temp.first][temp.second] + 1;
				check[x][y] = check[temp.first][temp.second];
				res.push(make_pair(x, y));
			}
		}
	}
	int Answer = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x =i+ dx[k]; int y = j + dy[k];
				if (check[x][y] && check[x][y]!=check[i][j])
				{
					if (Answer == -1 || Answer > d[i][j] + d[x][y])
					{
						Answer = d[i][j] + d[x][y];
					}
				}
			}
		}
	}
	cout << Answer << '\n';
}
void dfs(int i, int j, int islandnum)
{
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	res.push(make_pair(i, j));
	check[i][j] = islandnum;
	d[i][j] = 0;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int x = temp.first + dx[k]; int y = temp.second + dy[k];
			if (map[x][y] == 1 && check[x][y]!=islandnum)
			{
				check[x][y] = islandnum;
				q.push(make_pair(x, y));
				res.push(make_pair(x, y));
				d[x][y] = 0;
			}
		}
	}

}