#include <iostream>
#include <queue>
using namespace std;
int map[52][52];
int check[52][52];
int dx[8] = { -1,-1,-1,0,0,1,1,1};
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
void bfs(int i, int j);
int main()
{
	int w = 1, h = 1;
	while (true)
	{
		cin >> w >> h;
		if (!w && !h)
		{
			break;
		}
		int answer = 0;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (!check[i][j] && map[i][j])
				{
					bfs(i, j);
					answer++;
				}
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				check[i][j] = 0;
				map[i][j] = 0;
			}
		}
		cout << answer << '\n';
	}
}
void bfs(int i, int j)
{
	queue<pair<int, int>> bf;
	check[i][j] = 1;
	bf.push(make_pair(i, j));
	while (!bf.empty())
	{
		pair<int, int> temp = bf.front();
		bf.pop();
		for (int k = 0; k < 8; k++)
		{
			int ix = temp.first+ dx[k]; int jy = temp.second+ dy[k];
			if (!check[ix][jy] && map[ix][jy])
			{
				check[ix][jy] = 1;
				bf.push(make_pair(ix, jy));
			}
		}
	}
}