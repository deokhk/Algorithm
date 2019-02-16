#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int field[1005][1005];
int check[1005][1005];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
	int m, n;
	cin >> m >> n;
	int remain = 0;
	queue<tuple<int, int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 0)
			{
				remain++;
			}
			else if (field[i][j] == 1)
			{
				q.push(make_tuple(i, j, 0));
				check[i][j] = 1;
			}
		}
	}
	int answer = 0;
	bool fin = false;
	int day = 0;
	while (!q.empty() &&!fin)
	{
		tuple<int, int, int> temp = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int x = get<0>(temp) + dx[k]; int y= get<1>(temp) + dy[k];
			if (1<= x && x<=n && 1<=y && y<=m && !field[x][y] && !check[x][y])
			{
				check[x][y] = 1;
				day = get<2>(temp) + 1;
				q.push(make_tuple(x, y, day));
				remain--;
			}
			if (!remain)
			{
				fin = true;
				answer = day;
				break;
			}
		}
	}
	if (fin)
	{
		cout << answer << '\n';
	}
	else
	{
		cout << "-1" << '\n';
	}


}